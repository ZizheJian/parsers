#pragma once

#include <stdexcept>
#include <string>

inline bool parse_bool(const std::string &text,const std::string &name)
{
    if(text=="true")
        return true;
    if(text=="false")
        return false;
    throw std::runtime_error(name+"必须是true或false："+text);
}
