import re

# 只允许数字，不允许正负号和多余的前导0。re.ASCII让\d只匹配0到9，和C++版一致
non_negative_integer_pattern=re.compile(r"0|[1-9]\d*",re.ASCII)

# 读出不超过max_value的整数。positive为True时不接受0，报错信息里写"正整数"，否则写"非负整数"，type_name是报错信息里的类型名
def parse_unsigned_integer(text:str,name:str,positive:bool,max_value:int,type_name:str)->int:
    kind="正整数" if positive else "非负整数"
    if not isinstance(text,str) or non_negative_integer_pattern.fullmatch(text) is None or (positive and text=="0"):
        raise ValueError(f"{name}必须是{kind}：{text}")
    value=int(text)
    if value>max_value:
        raise ValueError(f"{name}必须是{type_name}范围内的{kind}：{text}")
    return value
