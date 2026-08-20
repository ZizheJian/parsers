from parse_uint64 import parse_uint64

def parse_uint32(text:str,name:str)->int:
    value=parse_uint64(text,name)
    if value>2**32-1:
        raise ValueError(f"{name}必须是uint32_t范围内的非负整数：{text}")
    return value
