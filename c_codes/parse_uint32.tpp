#pragma once

#include <cstdint>
#include <limits>
#include <stdexcept>
#include <string>
#include "check_non_negative_integer.tpp"

inline uint32_t parse_uint32(const std::string &text,const std::string &name="")
{
    check_non_negative_integer(text,name);
    uint64_t value=0;
    try
    {
        value=std::stoull(text);
    }
    catch(const std::out_of_range &)
    {
        // 超出uint64_t范围的数当作uint64_t的最大值，下面同样会报超出uint32_t范围
        value=std::numeric_limits<uint64_t>::max();
    }
    if(value>std::numeric_limits<uint32_t>::max())
        throw std::runtime_error(name+"必须是uint32_t范围内的非负整数："+text);
    return static_cast<uint32_t>(value);
}
