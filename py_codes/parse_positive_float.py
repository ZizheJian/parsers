import math
import struct
from .check_positive_decimal import check_positive_decimal

def parse_positive_float(text:str,name:str="")->float:
    check_positive_decimal(text,name)
    value=float(text)
    # 转成float精度：太小时得到0或一个很小的数，超出float范围的有限数会让struct报OverflowError
    try:
        value=struct.unpack("f",struct.pack("f",value))[0]
    except OverflowError:
        value=math.inf
    if not value>0 or not math.isfinite(value):
        raise ValueError(f"{name}必须是float范围内的有限正数：{text}")
    return value
