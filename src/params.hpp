#pragma once

#include <random>
#include <string>

namespace param {

    // general parameter
    int gene_length = 100;
    std::string encoding_method = "bin";

    // instance parameter
    std::string instance_name = "";
    int dimension = 0;
    int objective_function_size = 0;
    double lower_limit = 0.;
    double upper_limit = 0.;

    // ga parameter
    int population_size = 50;
    int offspring_size = 50;
    int max_generation = 100;
    double mutation_rate = 0.01;

    // other paramter
    int seed = 0;
    std::mt19937 mt(seed);
    std::string output_filename = "./../data/result/res.csv";
}