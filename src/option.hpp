#pragma once

#include <string>

#include "params.hpp"
#include "problems.hpp"

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
        if(opt == "-o") param::output_filename = "./../data/result/" + args + ".csv";
        if(opt == "-s") param::seed = std::stoi(args);
        if(opt == "-g") param::max_generation = std::stoi(args);
        if(opt == "-p") param::population_size = std::stoi(args);
        if(opt == "-c") param::offspring_size = std::stoi(args);
        if(opt == "-r") param::mutation_rate = std::stoi(args);
        if(opt == "-l") param::gene_length = std::stoi(args);
        if(opt == "-i") param::instance_name = args;
        if(opt == "-e") param::encoding_method = args;
    }
    param::mt = std::mt19937(param::seed);
    setting_instance_parameter();
}