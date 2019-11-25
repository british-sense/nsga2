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

void ZDT1_setting(){
    param::dimension = 30;
    param::objective_function_size = 2;
    param::lower_limit = 0.;
    param::upper_limit = 1.;
}

std::vector<double> ZDT1(const std::vector<double> & x){
    std::vector<double> f(param::objective_function_size);
    f.at(0) = x.at(0);
    double g = 1.;
    for(int dim = 1; dim < param::dimension; dim++) g += (9 * x.at(dim)) / (param::dimension - 1);
    f.at(1) = g * (1 - std::sqrt(x.at(0) / g));
    return f;
}

void ZDT2_setting(){
    param::dimension = 30;
    param::objective_function_size = 2;
    param::lower_limit = 0.;
    param::upper_limit = 1.;
}

std::vector<double> ZDT2(const std::vector<double> & x){
    std::vector<double> f(param::objective_function_size);
    f.at(0) = x.at(0);
    double g = 1.;
    for(int dim = 1; dim < param::dimension; dim++) g += (9 * x.at(dim)) / (param::dimension - 1);
    f.at(1) = g * (1 - std::pow(x.at(0) / g, 2));
    return f;
}

void setting_instance_parameter(){
    if(param::instance_name == "SCH") SCH_setting();
    if(param::instance_name == "FON") FON_setting();
    if(param::instance_name == "ZDT1") ZDT1_setting();
    if(param::instance_name == "ZDT2") ZDT2_setting();
}