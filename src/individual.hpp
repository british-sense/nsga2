#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "problems.hpp"

struct Individual {

    std::vector<std::vector<int>> gene;
    std::vector<double> x;
    std::vector<double> f;
    int rank;
    double cd;

    Individual();

    void init();
    void bit2real();
    void evaluate();
    void mutation();
    void output(std::string str);

    bool operator > (const Individual & indiv) const {
		return ((f.at(0) >= indiv.f.at(0) && f.at(1) > indiv.f.at(1)) || (f.at(0) > indiv.f.at(0) && f.at(1) >= indiv.f.at(1)));
	}
};

Individual::Individual() : gene(std::vector<std::vector<int>>(param::dimension, std::vector<int>(param::bit_length))), x(std::vector<double>(param::dimension)), f(std::vector<double>(param::objective_function_size)) {
}

void Individual::init() {
    std::uniform_int_distribution<int> bit(0, 1);
    for(int dim = 0; dim < param::dimension; dim++) {
        for(int locus = 0; locus < param::bit_length; locus++) {
            gene.at(dim).at(locus) = bit(param::mt);
        }
    }
    evaluate();
}

void Individual::bit2real() {
    for(int dim = 0; dim < param::dimension; dim++) {
        x.at(dim) = 0;
        for(int locus = 0; locus < param::bit_length; locus++) {
            x.at(dim) += std::pow(2., param::bit_length - locus - 1) * gene.at(dim).at(locus);
        }
        x.at(dim) = param::lower_limit + (param::upper_limit - param::lower_limit) * x.at(dim) / (std::pow(2., param::bit_length) - 1);
    }
}

void Individual::evaluate() {
    bit2real();
    f = SCH(x);
}

void Individual::mutation() {
    std::uniform_real_distribution<double> p(0., 1.);
    for(int dim = 0; dim < param::dimension; dim++) {
        for(int locus = 0; locus < param::bit_length; locus++) {
            if(p(param::mt) <= param::mutation_rate) gene.at(dim).at(locus) ^= 1;
        }
    }
}

void Individual::output(std::string str = "") {
    if(str != "") std::cout << "[" + str + "]" << std::endl;
    for(int dim = 0; dim < param::dimension; dim++) {
        std::cout << "gene[" + std::to_string(dim) + "] : ";
        for(int locus = 0; locus < param::bit_length; locus++) {
            std::cout << gene.at(dim).at(locus);
        }
        std::cout << std::endl;
    }
    std::cout << "x : ";
    for(int dim = 0; dim < param::dimension; dim++) {
        std::cout << x.at(dim) << ", ";
    }
    std::cout << std::endl;
    std::cout << "f : ";
    for(int obj = 0; obj < param::objective_function_size; obj++) {
        std::cout << f.at(obj) << ", ";
    }
    std::cout << std::endl;
    std::cout << "rank : " << rank << std::endl;
    std::cout << "cd : " << cd << std::endl;
}
