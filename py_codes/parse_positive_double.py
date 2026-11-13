import math
from .check_positive_decimal import check_positive_decimal

def parse_positive_double(text:str,name:str="")->float:
    check_positive_decimal(text,name)
    # float遇到超出范围的数不报错：太大时得到inf，太小时得到0或一个很小的数，所以下面统一检查
    value=float(text)
    if not value>0 or not math.isfinite(value):
        raise ValueError(f"{name}必须是double范围内的有限正数：{text}")
    return value
