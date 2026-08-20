UINT64_MAX=2**64-1

def parse_uint64(text:str,name:str)->int:
    try:
        value=int(text)
    except (TypeError,ValueError):
        raise ValueError(f"{name}必须是非负整数：{text}") from None
    if (str(value)!=text and "+"+str(value)!=text) or not 0<=value<=UINT64_MAX:
        raise ValueError(f"{name}必须是uint64_t范围内的非负整数：{text}")
    return value
