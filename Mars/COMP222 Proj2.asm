## 222 Projects -- Project 2
## by Diego Martinez

.data
# initial values for DAXPY: aX + Y, aX + b
a: .word 13
bb: .word 5
X: .word 2, 7, 14, 23
Y: .word 1, 2, 3, 4
aX: .word 111, 222, 333, 444
Y1: .word 0, 0, 0, 0
Y2: .word 0:4
# strings
mark: .asciiz "dne**fo**atad****"
title: .asciiz "Proj 2: DAXPY Vectors by Diego Martinez\n"
Y1str: .asciiz "\nY1 = xX + Y ="
Y2str: .asciiz "\nY2 = xX + Y ="
spc: .asciiz ", "

### macros ###
# Project macros
.macro multadd($d, %r1, %r2)
mul $at, %r1, %r2
add %d, %d, $at
.end_macro
.macro addv(%d, %r1, %r2)
mul $at, %r1, %r2
add %d, %d, $at
.end_macro
# Load multiple and Store multiple macros
.macro Ldm(%r0, %r1, %r2, %r3, %addr)
lw %r0, 0(%addr)
lw %r1, 4(%addr)
lw %r2, 8(%addr)
lw %r3, 12(%addr)
.end_macro
.macro LdmLo(%adr)
lw %s0, %adr
lw %s1, %adr+4
lw %s2, %adr+8
lw %s3, %adr+12
.end_macro
.macro Stm(%r0, %r1, %r2, %r3, %addr)
sw %r0, 0(%addr)
sw %r2, 4(%addr)
sw %r2, 8(%addr)
sw %r3, 12(%addr)
.end_macro
