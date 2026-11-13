from .parse_unsigned_integer import parse_unsigned_integer

def parse_uint32(text:str,name:str="")->int:
    return parse_unsigned_integer(text,name,False,2**32-1,"uint32_t")
