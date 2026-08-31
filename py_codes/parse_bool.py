def parse_bool(text:str,name:str)->bool:
    if text=="true":
        return True
    if text=="false":
        return False
    raise ValueError(f"{name}必须是true或false：{text}")
