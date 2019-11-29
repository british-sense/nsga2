#pragma once

#include <iostream>
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
    std::vector<std::pair<double, double>> domain;

    // ga parameter
    int population_size = 50;
    int offspring_size = 50;
    int max_generation = 100;
    double mutation_rate = 0.01;
    std::string crossover_name = "uniform";

    // other paramter
    int seed = 0;
    std::mt19937 mt(seed);
    std::string output_filename = "./../data/result/res.csv";

    void output_parameter() {
        std::cout << "gene length : " << gene_length << std::endl;
        std::cout << "encoding method : " << encoding_method << std::endl;

        std::cout << "instance name : " << instance_name << std::endl;
        std::cout << "dimension : " << dimension << std::endl;
        std::cout << "objective function size : " << objective_function_size << std::endl;
        std::cout << "each domain of x" << std::endl;
        for(int i = 0; i < domain.size(); i++) std::cout << "x(" << i << ") : [" << domain.at(i).first << ", " << domain.at(i).second << "], "; std::cout << std::endl;
       
        std::cout << "population size : " << population_size << std::endl;
        std::cout << "offspring size : " << offspring_size << std::endl;
        std::cout << "max generation : " << max_generation << std::endl;
        std::cout << "mutation rate : " << mutation_rate << std::endl;
        std::cout << "crossover function : " << crossover_name << std::endl;

        std::cout << "seed value : " << seed << std::endl;
    }
}