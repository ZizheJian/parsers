#pragma once

#include <cmath>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include "check_positive_decimal.tpp"

inline double parse_positive_double(const std::string &text,const std::string &name)
{
    check_positive_decimal(text,name);
    // strtod遇到超出范围的数不报错：太大时得到inf，太小时得到0或一个很小的数，所以下面统一检查
    double value=std::strtod(text.c_str(),nullptr);
    if(!(value>0)||!std::isfinite(value))
        throw std::runtime_error(name+"必须是double范围内的有限正数："+text);
    return value;
}
