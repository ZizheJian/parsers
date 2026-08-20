#pragma once

inline uint64_t parse_uint64(const std::string &text,const std::string &name)
{
    size_t parsed_character_num=0;
    uint64_t value=0;
    try
    {
        value=std::stoull(text,&parsed_character_num);
    }
    catch (...)
    {
        throw std::runtime_error(name+"必须是非负整数："+text);
    }
    if (parsed_character_num!=text.size() ||
        (std::to_string(value)!=text && "+"+std::to_string(value)!=text))
        throw std::runtime_error(name+"必须是uint64_t范围内的非负整数："+text);
    return value;
}
