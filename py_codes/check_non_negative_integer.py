import re

# 只允许数字，不允许正负号和多余的前导0。re.ASCII让\d只匹配0到9，和C++版一致
non_negative_integer_pattern=re.compile(r"0|[1-9]\d*",re.ASCII)

def check_non_negative_integer(text:str,name:str):
    if not isinstance(text,str) or non_negative_integer_pattern.fullmatch(text) is None:
        raise ValueError(f"{name}必须是非负整数：{text}")
