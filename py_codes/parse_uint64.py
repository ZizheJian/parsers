import re

UINT64_MAX=2**64-1
# 只允许数字和开头的+号，不允许多余的前导0。re.ASCII让\d只匹配0到9，和C++版一致
non_negative_integer_pattern=re.compile(r"\+?(?:0|[1-9]\d*)",re.ASCII)

def parse_uint64(text:str,name:str="")->int:
    if not isinstance(text,str) or non_negative_integer_pattern.fullmatch(text) is None:
        raise ValueError(f"{name}必须是非负整数：{text}")
    value=int(text)
    if value>UINT64_MAX:
        raise ValueError(f"{name}必须是uint64_t范围内的非负整数：{text}")
    return value
