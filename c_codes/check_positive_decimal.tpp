#pragma once

#include <regex>
#include <stdexcept>
#include <string>

// 只允许数字、小数点、开头的+号和科学计数法，例如1、+1.5、.5、1e-3，不接受inf、nan、空格和负号
inline void check_positive_decimal(const std::string &text,const std::string &name)
{
    static const std::regex positive_decimal_pattern(R"(\+?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?)");
    if(!std::regex_match(text,positive_decimal_pattern))
        throw std::runtime_error(name+"必须是正数："+text);
}
