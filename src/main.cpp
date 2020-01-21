#include <iostream>
#include <vector>
#include <string>

#include "option.hpp"
#include "individual.hpp"
#include "nsga2.hpp"
#include "utils.hpp"

void repeated_permutation(int pos, std::vector<int> & v, const int size, const int start, const int end) {

    if(pos == size) {
        for(int d = 0; d < param::dimension; d++) param::domain.at(d) = std::make_pair(0.0, 0.0);
        std::vector<Individual> population = nsga2();
        std::string filename = "";
        param::output_filename = filename;
        // output_file(population);
        return;
    }
    for(int i = start; i < end; i++) {
        v.at(pos) = i;
        repeated_permutation(pos + 1, v, size, start, end);
    }
}

int main(int argc, char * argv[]) {

    params_setting(argc, argv);
    param::output_parameter();

    // std::vector<Individual> population = nsga2();

    // output_file(population);

    std::vector<int> v(param::dimension);
    repeated_permutation(0, v, param::dimension, 0, param::partition);
}