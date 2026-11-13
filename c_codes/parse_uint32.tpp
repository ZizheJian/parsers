#pragma once

#include <charconv>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <system_error>
#include "check_non_negative_integer.tpp"

inline uint32_t parse_uint32(const std::string &text,const std::string &name="")
{
    check_non_negative_integer(text,name);
    uint32_t value=0;
    // 写法已经检查过，这里只可能成功或者超出uint32_t范围
    if(std::from_chars(text.data(),text.data()+text.size(),value).ec!=std::errc())
        throw std::runtime_error(name+"必须是uint32_t范围内的非负整数："+text);
    return value;
}
