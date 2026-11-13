#pragma once

#include <cstdint>
#include <limits>
#include <regex>
#include <stdexcept>
#include <string>

inline uint32_t parse_positive_uint32(const std::string &text,const std::string &name="")
{
    // 只允许数字，不允许0、正负号和前导0
    static const std::regex positive_integer_pattern(R"([1-9]\d*)");
    if(!std::regex_match(text,positive_integer_pattern))
        throw std::runtime_error(name+"必须是正整数："+text);
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
        throw std::runtime_error(name+"必须是uint32_t范围内的正整数："+text);
    return static_cast<uint32_t>(value);
}
