#pragma once

#include <cstdint>
#include <limits>
#include <string>
#include "parse_unsigned_integer.tpp"

inline uint32_t parse_positive_uint32(const std::string &text,const std::string &name="")
{
    return static_cast<uint32_t>(parse_unsigned_integer(text,name,true,std::numeric_limits<uint32_t>::max(),"uint32_t"));
}
