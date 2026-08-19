from parse_uint32 import parse_uint32

def parse_positive_uint32(text:str,name:str)->int:
    value=parse_uint32(text,name)
    if value==0:
        raise ValueError(f"{name}必须是正整数：{text}")
    return value
