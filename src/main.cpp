#include <iostream>
#include <vector>
#include <string>

#include "option.hpp"
#include "individual.hpp"
#include "nsga2.hpp"
#include "utils.hpp"

void repeated_permutation(const int start, const int end, std::vector<int> & v) {

    if(v.size() == param::dimension) {
        std::vector<Individual> population = nsga2();
        std::string filename = "";
        param::output_filename = filename;
        output_file(population);
        v.clear();
        return;
    }
    for(int i = start; i <= end; i++) {
        v.emplace_back(i);
        repeated_permutation(start, end, v);
    }
}

int main(int argc, char * argv[]) {

    params_setting(argc, argv);
    param::output_parameter();

    std::vector<Individual> population = nsga2();

    output_file(population);
}