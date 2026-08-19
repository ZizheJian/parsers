UINT32_MAX=2**32-1

def parse_uint32(text:str,name:str)->int:
    try:
        value=int(text)
    except (TypeError,ValueError):
        raise ValueError(f"{name}必须是非负整数：{text}") from None
    if str(value)!=text and "+"+str(value)!=text or not 0<=value<=UINT32_MAX:
        raise ValueError(f"{name}必须是uint32_t范围内的非负整数：{text}")
    return value
