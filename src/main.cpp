#include <iostream>
#include <vector>
#include <string>
#include <list>

#include "option.hpp"
#include "individual.hpp"
#include "nsga2.hpp"
#include "utils.hpp"


int main(int argc, char * argv[]) {

    params_setting(argc, argv);
    param::output_parameter();

    std::vector<Individual> population = nsga2();

    output_file(population);
}