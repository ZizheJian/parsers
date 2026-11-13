#pragma once

#include <cstdint>
#include <stdexcept>
#include <string>
#include "check_non_negative_integer.tpp"

inline uint64_t parse_uint64(const std::string &text,const std::string &name="")
{
    check_non_negative_integer(text,name);
    try
    {
        return std::stoull(text);
    }
    catch(const std::out_of_range &)
    {
        throw std::runtime_error(name+"必须是uint64_t范围内的非负整数："+text);
    }
}
