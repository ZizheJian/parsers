#pragma once

#include <cstdint>
#include <limits>
#include <string>
#include "parse_unsigned_integer.tpp"

inline uint64_t parse_uint64(const std::string &text,const std::string &name="")
{
    return parse_unsigned_integer(text,name,false,std::numeric_limits<uint64_t>::max(),"uint64_t");
}
