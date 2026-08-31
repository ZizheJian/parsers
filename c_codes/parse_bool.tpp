#pragma once

inline bool parse_bool(std::string text,std::string name)
{
    if (text=="true")
        return true;
    if (text=="false")
        return false;
    throw std::runtime_error(name+"必须是true或false："+text);
}
