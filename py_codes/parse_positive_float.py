import math
import struct

def parse_positive_float(text:str,name:str)->float:
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
