import re

UINT32_MAX=2**32-1
# 只允许数字，不允许0、正负号和前导0。re.ASCII让\d只匹配0到9，和C++版一致
positive_integer_pattern=re.compile(r"[1-9]\d*",re.ASCII)

def parse_positive_uint32(text:str,name:str="")->int:
    if not isinstance(text,str) or positive_integer_pattern.fullmatch(text) is None:
        raise ValueError(f"{name}必须是正整数：{text}")
    value=int(text)
    if value>UINT32_MAX:
        raise ValueError(f"{name}必须是uint32_t范围内的正整数：{text}")
    return value
