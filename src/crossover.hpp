#pragma once

#include <tuple>
#include <functional>

#include "individual.hpp"

#include "params.hpp"

std::function<std::tuple<Individual, Individual>(const Individual & parentA, const Individual & parentB)> crossover;

std::tuple<Individual, Individual> uniform_crossover(const Individual & parentA, const Individual & parentB) {
    Individual childA = parentA, childB = parentB;
    std::uniform_int_distribution<int> bit(0, 1);
    for(int dim = 0; dim < param::dimension; dim++) {
        for(int locus = 0; locus < param::gene_length; locus++) {
            if(bit(param::mt)) {
                std::swap(childA.gene.at(dim).at(locus), childB.gene.at(dim).at(locus));
            }
        }
    }
    return {childA, childB};
}

std::tuple<Individual, Individual> onepoint_crossover(const Individual & parentA, const Individual & parentB) {
    Individual childA = parentA, childB = parentB;
    std::uniform_int_distribution<int> gene_range(0, param::gene_length - 1);
    for(int dim = 0; dim < param::dimension; dim++) {
        int cut = gene_range(param::mt);
        for(int locus = cut; locus < param::gene_length; locus++) {
            std::swap(childA.gene.at(dim).at(locus), childB.gene.at(dim).at(locus));
        }
    }
    return {childA, childB};
}

void setting_crossover_parameter() {
    if(param::crossover_name == "uniform") crossover = uniform_crossover;
    if(param::crossover_name == "onepoint") crossover = onepoint_crossover;
}

