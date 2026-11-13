#pragma once

#include <cstdint>
#include <regex>
#include <stdexcept>
#include <string>

inline uint64_t parse_uint64(const std::string &text,const std::string &name)
{
    // 只允许数字和开头的+号，不允许多余的前导0
    static const std::regex non_negative_integer_pattern(R"(\+?(?:0|[1-9]\d*))");
    if(!std::regex_match(text,non_negative_integer_pattern))
        throw std::runtime_error(name+"必须是非负整数："+text);
    try
    {
        return std::stoull(text);
    }
    catch(const std::out_of_range &)
    {
        throw std::runtime_error(name+"必须是uint64_t范围内的非负整数："+text);
    }
}
