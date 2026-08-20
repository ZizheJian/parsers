import math
import re
import struct

positive_decimal_pattern=re.compile(r"\+?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?")

def parse_positive_float(text:str,name:str)->float:
    if not isinstance(text,str) or positive_decimal_pattern.fullmatch(text) is None:
        raise ValueError(f"{name}必须是正数：{text}")
    try:
        value=float(text)
    except (TypeError,ValueError):
        raise ValueError(f"{name}必须是正数：{text}") from None
    try:
        float_value=struct.unpack("f",struct.pack("f",value))[0]
    except OverflowError:
        float_value=math.inf
    if not math.isfinite(value) or not float_value>0 or not math.isfinite(float_value):
        raise ValueError(f"{name}必须是float范围内的有限正数：{text}")
    return float_value
