from test import testRepeated 

def toHex(number):
    return hex(number)

def toDecimal(number):
    return int(number,16)

def toBinary(number):
    return bin(number)

print(toBinary(toDecimal(toHex(10))))
