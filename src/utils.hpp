#pragma once

#include <vector>
#include <fstream>
#include <string>

#include "params.hpp"
#include "individual.hpp"

void output_file(const std::vector<Individual> & population) {
    std::ofstream output_file(param::output_filename);
    for(int obj = 0; obj < param::objective_function_size; obj++) output_file << "f" + std::to_string(obj) + ", "; std::cout << std::endl;
    for(auto indiv : population) {
        for(int obj = 0; obj < param::objective_function_size; obj++) {
            output_file << indiv.f.at(obj) << ", ";
        }
        std::cout << std::endl;
    }
}