#pragma once

#include <cstdint>
#include <regex>
#include <stdexcept>
#include <string>

// 读出不超过max_value的整数，只允许数字，不允许正负号和多余的前导0
// positive为true时不接受0，报错信息里写"正整数"，否则写"非负整数"，type_name是报错信息里的类型名
inline uint64_t parse_unsigned_integer(const std::string &text,const std::string &name,bool positive,uint64_t max_value,const std::string &type_name)
{
    static const std::regex non_negative_integer_pattern(R"(0|[1-9]\d*)");
    const std::string kind=positive?"正整数":"非负整数";
    if(!std::regex_match(text,non_negative_integer_pattern)||(positive&&text=="0"))
        throw std::runtime_error(name+"必须是"+kind+"："+text);
    try
    {
        uint64_t value=std::stoull(text);
        if(value<=max_value)
            return value;
    }
    catch(const std::out_of_range &)
    {
        // 超出uint64_t范围，和超出max_value一样报错
    }
    throw std::runtime_error(name+"必须是"+type_name+"范围内的"+kind+"："+text);
}
