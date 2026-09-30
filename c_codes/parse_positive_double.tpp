#pragma once

inline double parse_positive_double(const std::string &text,const std::string &name)
{
    static const std::regex positive_decimal_pattern(R"(\+?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?)");
    if(!std::regex_match(text,positive_decimal_pattern))
        throw std::runtime_error(name+"必须是正数："+text);
    size_t parsed_character_num=0;
    double value=0;
    try
    {
        value=std::stod(text,&parsed_character_num);
    }
    catch (...)
    {
        throw std::runtime_error(name+"必须是正数："+text);
    }
    if(parsed_character_num!=text.size()||!(value>0)||!std::isfinite(value))
        throw std::runtime_error(name+"必须是double范围内的有限正数："+text);
    return value;
}
