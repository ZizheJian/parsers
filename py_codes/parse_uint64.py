from .check_non_negative_integer import check_non_negative_integer

UINT64_MAX=2**64-1

def parse_uint64(text:str,name:str="")->int:
    check_non_negative_integer(text,name)
    value=int(text)
    if value>UINT64_MAX:
        raise ValueError(f"{name}必须是uint64_t范围内的非负整数：{text}")
    return value
