#pragma once

#include "params.hpp"

void SCH_setting(){
    param::dimension = 1;
    param::objective_function_size = 2;
    param::lower_limit = -1000.;
    param::upper_limit = 1000.;
}

std::vector<double> SCH(const std::vector<double> & x){
    std::vector<double> f(param::objective_function_size);
    f.at(0) = x.at(0) * x.at(0);
    f.at(1) = (x.at(0) - 2) * (x.at(0) - 2);
    return f;
}

void FON_setting(){
    param::dimension = 3;
    param::objective_function_size = 2;
    param::lower_limit = -4.;
    param::upper_limit = 4.;
}

std::vector<double> FON(const std::vector<double> & x){
    std::vector<double> f(param::objective_function_size);
    for(int obj = 0; obj < param::objective_function_size; obj++){
        double A = 0;
        for(int dim = 0; dim < param::dimension; dim++) A += std::pow((x.at(dim) - (std::pow(-1., obj + 1) - std::sqrt(3))), 2);
        f.at(obj) = 1 - exp(-A);
    }
    return f;
}

void setting_instance_parameter(){
    if(param::instance_name == "SCH") SCH_setting();
    if(param::instance_name == "FON") FON_setting();
}