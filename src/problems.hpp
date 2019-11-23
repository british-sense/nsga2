#pragma once

#include "params.hpp"

std::vector<double> SCH(const std::vector<double> & x){
    std::vector<double> f(param::objective_function_size);
    f.at(0) = x.at(0) * x.at(0);
    f.at(1) = (x.at(0) - 2) * (x.at(0) - 2);
    return f;
}