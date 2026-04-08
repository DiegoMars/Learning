## 222 Projects -- Project 2
## by Diego Martinez

# Register Map
# a: $t8
# b: $t9
# X(0:3): $s(0:3)
# Y(0:3): $s(4:7)
# aX: $s(0:3)
# Y1: $t(0:3)
# Y2: $t(4:7)
.data
# initial values for DAXPY: aX + Y, aX + b
a: .word 13
b: .word 5
X: .word 2, 7, 14, 23
Y: .word 1, 2, 3, 4
Y1: .word 0:4
Y2: .word 0:4
# strings
mark: .asciiz "dne**fo**atad****"
title: .asciiz "Proj 2: DAXPY Vectors by Diego Martinez\n"
Y1str: .asciiz "\nY1 = aX + Y = "
Y2str: .asciiz "\nY2 = aX + b = "
spc: .asciiz ", "

### macros ###
.macro mulvs # multiply a and X
  mul $s0, $t8, $s0
  mul $s1, $t8, $s1
  mul $s2, $t8, $s2
  mul $s3, $t8, $s3
.end_macro
.macro addv # Adds aX and Y, stores in Y1
  add $t0, $s0, $s4
  add $t1, $s1, $s5
  add $t2, $s2, $s6
  add $t3, $s3, $s7
.end_macro
.macro addvs # Adds aX and b, stores in Y2
  add $t4, $t9, $s0
  add $t5, $t9, $s1
  add $t6, $t9, $s2
  add $t7, $t9, $s3
.end_macro
.macro Ldm(%r0, %r1, %r2, %r3, %addr)
  lw %r0, 0(%addr)
  lw %r1, 4(%addr)
  lw %r2, 8(%addr)
  lw %r3, 12(%addr)
.end_macro
.macro Stm(%r0, %r1, %r2, %r3, %addr)
  sw %r0, 0(%addr)
  sw %r1, 4(%addr)
  sw %r2, 8(%addr)
  sw %r3, 12(%addr)
.end_macro
# Print macros #
.macro _GUI_out(%str)
  la $a0, %str
  li $v0, 55 # GUI message code
  li $a1, 1 # message type is info
  syscall
.end_macro
.macro Print_str(%str)
  la $a0, %str
  li $v0, 4
  syscall
.end_macro
.macro Comma
  li $v0, 4
  la $a0, spc
  syscall
.end_macro
.macro PrintResult(%y)
  li $v0, 1
  lw $a0, 0(%y)
  syscall
  Comma
  li $v0, 1
  lw $a0, 4(%y)
  syscall
  Comma
  li $v0, 1
  lw $a0, 8(%y)
  syscall
  Comma
  li $v0, 1
  lw $a0, 12(%y)
  syscall
.end_macro

.text
main:
  # Loading registers #
  lw $t8, a
  lw $t9, b
  la $t0, X
  Ldm($s0, $s1, $s2, $s3, $t0)
  la $t0, Y
  Ldm($s4, $s5, $s6, $s7, $t0)
  # End loading registers #

  # Doing aX + Y = Y1 now
  mulvs       # Again, does aX
  addv        # Does the addition of aX + Y
  la $t4, Y1  # Not using t4 for Y1 yet
  Stm($t0, $t1, $t2, $t3, $t4) # Storing the values of Y1 into memory

  # Doing aX + b = Y2 now
  # aX is already done
  addvs       # Does the addition of aX + b
  la $t0, Y2  # No longer using t0 for Y1
  Stm($t4, $t5, $t6, $t7, $t0) # Storing the values of Y2 into memory

  # Printing results
  Print_str(title)
  Print_str(Y1str)
  la $t0, Y1
  PrintResult($t0)
  Print_str(Y2str)
  la $t0, Y2
  PrintResult($t0)

  li $v0, 10
  syscall
