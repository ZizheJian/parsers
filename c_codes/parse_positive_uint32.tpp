#pragma once

#include <cstdint>
#include <stdexcept>
#include <string>
#include "parse_uint32.tpp"

inline uint32_t parse_positive_uint32(const std::string &text,const std::string &name)
{
    uint32_t value=parse_uint32(text,name);
    if(value==0)
        throw std::runtime_error(name+"必须是正整数："+text);
    return value;
}
