import re

# 只允许数字、小数点和科学计数法，例如1、1.5、.5、1e-3，不接受开头的正负号、inf、nan和空格。re.ASCII让\d只匹配0到9，和C++版一致
positive_decimal_pattern=re.compile(r"(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?",re.ASCII)

def check_positive_decimal(text:str,name:str):
    if not isinstance(text,str) or positive_decimal_pattern.fullmatch(text) is None:
        raise ValueError(f"{name}必须是正数：{text}")
