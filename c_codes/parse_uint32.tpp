#pragma once

inline uint32_t parse_uint32(const std::string &text,const std::string &name)
{
    uint64_t value=parse_uint64(text,name);
    if (value>std::numeric_limits<uint32_t>::max())
        throw std::runtime_error(name+"必须是uint32_t范围内的非负整数："+text);
    return static_cast<uint32_t>(value);
}
