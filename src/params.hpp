#pragma once

#include <random>
#include <string>

namespace param {

    // general parameter
    const int bit_length = 10;

    // problems paramter
    std::string problem_name = "SCH";
    int dimension = 1;
    int objective_function_size = 2;
    double lower_limit = -1000;
    double upper_limit = 1000;

    // ga parameter
    int population_size = 50;
    int offspring_size = 50;
    int max_generation = 3;
    double mutation_rate = 0.01;

    // other paramter
    int seed = 0;
    std::mt19937 mt;
}