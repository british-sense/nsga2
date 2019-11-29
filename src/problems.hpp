#pragma once

#include <functional>

#include "params.hpp"

std::function<std::vector<double>(const std::vector<double> & x)> instance;

void SCH_setting() {
    param::dimension = 1;
    param::objective_function_size = 2;
    for(int dim = 0; dim < param::dimension; dim++) param::domain.emplace_back(std::pair(-1000., 1000.));
}

std::vector<double> SCH(const std::vector<double> & x) {
    std::vector<double> f(param::objective_function_size);
    f.at(0) = x.at(0) * x.at(0);
    f.at(1) = (x.at(0) - 2) * (x.at(0) - 2);
    return f;
}

void FON_setting() {
    param::dimension = 3;
    param::objective_function_size = 2;
    for(int dim = 0; dim < param::dimension; dim++) param::domain.emplace_back(std::pair(-4., 4.));
}

std::vector<double> FON(const std::vector<double> & x) {
    std::vector<double> f(param::objective_function_size);
    for(int obj = 0; obj < param::objective_function_size; obj++){
        double A = 0;
        for(int dim = 0; dim < param::dimension; dim++) A += std::pow((x.at(dim) - (std::pow(-1., obj + 1) - std::sqrt(3))), 2);
        f.at(obj) = 1 - exp(-A);
    }
    return f;
}

void ZDT1_setting() {
    param::dimension = 30;
    param::objective_function_size = 2;
    for(int dim = 0; dim < param::dimension; dim++) param::domain.emplace_back(std::pair(0., 1.));
}

std::vector<double> ZDT1(const std::vector<double> & x) {
    std::vector<double> f(param::objective_function_size);
    f.at(0) = x.at(0);
    double g = 1.;
    for(int dim = 1; dim < param::dimension; dim++) g += (9 * x.at(dim)) / (param::dimension - 1);
    f.at(1) = g * (1 - std::sqrt(x.at(0) / g));
    return f;
}

void ZDT2_setting() {
    param::dimension = 30;
    param::objective_function_size = 2;
    for(int dim = 0; dim < param::dimension; dim++) param::domain.emplace_back(std::pair(0., 1.));
}

std::vector<double> ZDT2(const std::vector<double> & x) {
    std::vector<double> f(param::objective_function_size);
    f.at(0) = x.at(0);
    double g = 1.;
    for(int dim = 1; dim < param::dimension; dim++) g += (9 * x.at(dim)) / (param::dimension - 1);
    f.at(1) = g * (1 - std::pow(x.at(0) / g, 2));
    return f;
}

void ZDT3_setting() {
    param::dimension = 30;
    param::objective_function_size = 2;
    for(int dim = 0; dim < param::dimension; dim++) param::domain.emplace_back(std::pair(0., 1.));
}

std::vector<double> ZDT3(const std::vector<double> & x) {
    const double pi = 3.141592653589793;
    std::vector<double> f(param::objective_function_size);
    f.at(0) = x.at(0);
    double g = 1.;
    for(int dim = 1; dim < param::dimension; dim++) g += (9 * x.at(dim)) / (param::dimension - 1);
    f.at(1) = g * (1 - std::sqrt(x.at(0) / g) - (x.at(0) / g) * std::sin(10 * pi * x.at(0)));
    return f;
}

void ZDT4_setting() {
    param::dimension = 10;
    param::objective_function_size = 2;
    for(int dim = 0; dim < 1; dim++) param::domain.emplace_back(std::pair(0., 1.));
    for(int dim = 1; dim < param::dimension; dim++) param::domain.emplace_back(std::pair(-5., 5.));
}

std::vector<double> ZDT4(const std::vector<double> & x) {
    const double pi = 3.141592653589793;
    std::vector<double> f(param::objective_function_size);
    f.at(0) = x.at(0);
    double g = 1. + 10 * (param::dimension - 1);
    for(int dim = 1; dim < param::dimension; dim++) g += x.at(dim) * x.at(dim) - 10 * std::cos(4 * pi * x.at(dim));
    f.at(1) = g * (1 - std::sqrt(x.at(0) / g));
    return f;
}

void ZDT6_setting() {
    param::dimension = 10;
    param::objective_function_size = 2;
    for(int dim = 0; dim < param::dimension; dim++) param::domain.emplace_back(std::pair(0., 1.));
}

std::vector<double> ZDT6(const std::vector<double> & x) {
    const double pi = 3.141592653589793;
    std::vector<double> f(param::objective_function_size);
    f.at(0) = 1 - std::exp(-4 * x.at(0)) * std::pow(std::sin(6 * pi * x.at(0)), 6);
    double g = 1.;
    for(int dim = 1; dim < param::dimension; dim++) g += (x.at(dim)) / (param::dimension - 1);
    g = 9 * std::pow(g, 0.25);
    f.at(1) = g * (1 - (f.at(0) / g) * (f.at(0) / g));
    return f;
}

void setting_instance_parameter() {
    if(param::instance_name == "SCH") {
        SCH_setting();
        instance = SCH;
    }
    if(param::instance_name == "FON") {
        FON_setting();
        instance = FON;
    }
    if(param::instance_name == "ZDT1") {
        ZDT1_setting();
        instance = ZDT1;
    }
    if(param::instance_name == "ZDT2") {
        ZDT2_setting();
        instance = ZDT2;
    }
    if(param::instance_name == "ZDT3") {
        ZDT3_setting();
        instance = ZDT3;
    }
    if(param::instance_name == "ZDT4") {
        ZDT4_setting();
        instance = ZDT4;
    }
    if(param::instance_name == "ZDT6") {
        ZDT6_setting();
        instance = ZDT6;
    }
}