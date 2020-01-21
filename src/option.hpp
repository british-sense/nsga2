#pragma once

#include <string>

#include "params.hpp"
#include "problems.hpp"
#include "crossover.hpp"

void params_setting(int argc, char * argv[]) {
    // -o : output filename
    // -s : seed value
    // -g : max generation count
    // -p : population size
    // -c : offspring size
    // -r : mutation rate
    // -l : gene length
    // -i : instance name
    // -e : encoding method
    for(int i = 1; i < argc; i++){
        std::string opt(argv[i]);
        std::string args(argv[(i + 1) % argc]);
        if(opt == "-o" || opt == "--output") param::output_filename = "./../data/result/" + args + ".csv";
        if(opt == "-s" || opt == "--seed") param::seed = std::stoi(args);
        if(opt == "-g" || opt == "--generation") param::max_generation = std::stoi(args);
        if(opt == "-p" || opt == "--population") param::population_size = std::stoi(args);
        if(opt == "-c" || opt == "--offspring") param::offspring_size = std::stoi(args);
        if(opt == "-r" || opt == "--mutation") param::mutation_rate = std::stoi(args);
        if(opt == "-l" || opt == "--length") param::gene_length = std::stoi(args);
        if(opt == "-i" || opt == "--instance") param::instance_name = args;
        if(opt == "-e" || opt == "--encode") param::encoding_method = args;
        if(opt == "--crossover") param::crossover_name = args;
        if(opt == "--partition") param::partition = std::stoi(args);
    }
    param::mt = std::mt19937(param::seed);
    setting_instance_parameter();
    setting_crossover_parameter();
}