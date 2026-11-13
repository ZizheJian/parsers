#pragma once

#include <regex>
#include <stdexcept>
#include <string>

// 只允许数字，不允许正负号和多余的前导0
inline void check_non_negative_integer(const std::string &text,const std::string &name)
{
    static const std::regex non_negative_integer_pattern(R"(0|[1-9]\d*)");
    if(!std::regex_match(text,non_negative_integer_pattern))
        throw std::runtime_error(name+"必须是非负整数："+text);
}
