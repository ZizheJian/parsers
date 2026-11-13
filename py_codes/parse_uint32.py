from .check_non_negative_integer import check_non_negative_integer

UINT32_MAX=2**32-1

def parse_uint32(text:str,name:str="")->int:
    check_non_negative_integer(text,name)
    value=int(text)
    if value>UINT32_MAX:
        raise ValueError(f"{name}必须是uint32_t范围内的非负整数：{text}")
    return value
