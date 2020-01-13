#pragma once

#include <vector>
#include <list>
#include <random>
#include <algorithm>
#include <tuple>
#include <numeric>

#include "params.hpp"
#include "individual.hpp"
#include "crossover.hpp"

void non_dominated_sorting (std::list<Individual> & family) {
    std::list<Individual> sort_family;
    for(int rank = 1; !family.empty(); rank++) {
        for(auto indiv1 = family.begin(); indiv1 != family.end(); indiv1++) {
            bool dominance = true;
            for(auto indiv2 = family.begin(); indiv2 != family.end(); indiv2++) {
                if(*indiv1 == *indiv2) continue;
                if(*indiv1 > *indiv2) {
                    dominance = false;
                    break;
                }
            }
            if(dominance) {
                indiv1->rank = rank;
                sort_family.emplace_back(*indiv1);
                auto erase_itr = indiv1--;
                family.erase(erase_itr);
            }
        }
    }
    family = sort_family;
}

void crowding_distance(std::list<Individual> & family) {
    for(int obj = 0; obj < param::objective_function_size; obj++) {
        family.sort([&](Individual indiv1, Individual indiv2){ return indiv1.f.at(obj) < indiv2.f.at(obj); });
        family.front().cd = family.back().cd = std::numeric_limits<double>::infinity();
        for(auto indiv = std::next(family.begin(), 1); indiv != std::next(family.begin(), family.size() - 1); indiv++) {
            indiv->cd += (std::next(indiv, 1)->f.at(obj) - std::prev(indiv, 1)->f.at(obj)) / (family.back().f.at(obj) - family.front().f.at(obj));
        }
    }
}

std::vector<Individual> crowded_tournament_selection(std::list<Individual> & family) {

    std::vector<Individual> next_population;
    for(int rank = 1; next_population.size() != param::population_size; rank++) {
        int count = 0;
        for(auto indiv = family.begin(); indiv->rank == rank; indiv++) {
            count++;
        }
        if(next_population.size() + count <= param::population_size) {
            for(int pop = 0; pop < count; pop++) {
                next_population.emplace_back(family.front());
                family.pop_front();
            }
        } else {
            std::list<Individual> temp(family.begin(), std::next(family.begin(), count));
            crowding_distance(temp);
            temp.sort([&](Individual indiv1, Individual indiv2){ return indiv1.cd > indiv2.cd; });
            while(next_population.size() != param::population_size) {
                next_population.emplace_back(temp.front());
                temp.pop_front();
            }
            break;
        }
    }
    return next_population;
}

std::vector<Individual> nsga2() {

    std::vector<Individual> population(param::population_size);
    for(auto & individual : population) individual.init();

    for(int generation = 1; generation < param::max_generation; generation++) {

        // generate offspring.
        std::uniform_int_distribution< int > population_range(0, population.size() - 1);
        std::vector<Individual> offspring(param::offspring_size);
        for(int i = 0; i < param::offspring_size; i += 2) {
            int indexA = population_range(param::mt);
            int indexB = population_range(param::mt);
            std::tie(offspring.at(i), offspring.at(i + 1)) = crossover(population.at(indexA) , population.at(indexB));
            offspring.at(i).mutation();
            offspring.at(i + 1).mutation();
            offspring.at(i).evaluate();
            offspring.at(i + 1).evaluate();
        }

        // merge population and offspring.
        std::list<Individual> family;
        for(int i = 0; i < population.size(); i++) family.emplace_back(population.at(i));
        for(int i = 0; i < offspring.size(); i++) family.emplace_back(offspring.at(i));

        // non-dominated sorting to family.
        for(auto & indiv : family) indiv.rank = 0;
        non_dominated_sorting(family);

        // extract next population from family.
        for(auto & indiv : family) indiv.cd = 0.;
        population = crowded_tournament_selection(family);
    }
    return population;
}