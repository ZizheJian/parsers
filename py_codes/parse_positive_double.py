import math
import re

positive_decimal_pattern=re.compile(r"\+?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?")

def parse_positive_double(text:str,name:str)->float:
    if not isinstance(text,str) or positive_decimal_pattern.fullmatch(text) is None:
        raise ValueError(f"{name}必须是正数：{text}")
    try:
        value=float(text)
    except (TypeError,ValueError):
        raise ValueError(f"{name}必须是正数：{text}") from None
    if not value>0 or not math.isfinite(value):
        raise ValueError(f"{name}必须是double范围内的有限正数：{text}")
    return value
