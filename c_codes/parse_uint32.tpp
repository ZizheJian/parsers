#pragma once

inline uint32_t parse_uint32(const std::string &text,const std::string &name)
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
    if (parsed_character_num!=text.size() || value>std::numeric_limits<uint32_t>::max())
        throw std::runtime_error(name+"必须是uint32_t范围内的非负整数："+text);
    return static_cast<uint32_t>(value);
}
