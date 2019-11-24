#include <fstream>

#include "individual.hpp"
#include "nsga2.hpp"

int main() {
    std::vector<Individual> population = nsga2();
    std::ofstream ofile("nsga2.csv");
    for(auto indiv : population) ofile << indiv.f.at(0) << ", " << indiv.f.at(1) << std::endl;
}