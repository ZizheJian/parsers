from .parse_unsigned_integer import parse_unsigned_integer

def parse_uint64(text:str,name:str="")->int:
    return parse_unsigned_integer(text,name,False,2**64-1,"uint64_t")
