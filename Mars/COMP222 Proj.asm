## 222 Projects -- Interrupts
## by Jeff Drobman
##version: 1.2 >11-11-25
#Interrupt vectors:
# 0-3 active
#VEC 0 = Keyboard, 1 = mouse
#reg map:  $t9 = stop val; $s0,$s1 for int vectors; $s2=EC
.data
vector: .ascii "#cev" #reserve 4 bytes
title: .asciiz  "222 Projects: Interrupts by Jeff D\n"
.align 2
prompt1: .asciiz "Enter Int TYPE: 0=NMI, 1=NVI, 2=VI, 9=Halt"
.align 2
prompt2: .asciiz "Enter Int Vector (0-15):"
.align 2
NMI_str: .asciiz "NMI interrupt!\n"
.align 2
NVI_str: .asciiz "NVI interrupt!\n"
.align 2
VI_str: .asciiz "Vectored interrupt!\n"
.align 2
Vect_str: .asciiz " ...Vector="
.align 2
Err_msg1: .asciiz "Error: invalid INT Type\n"
.align 2
Err_msg2: .asciiz "Error: invalid Entry\n"
.align 2
Halt_msg: .asciiz "Halted! Good-bye"
.align 2
Stop_msg: .asciiz "Stopped out!"
newLn: .asciiz "\n"
.align 2
end_data: .asciiz "$***$***"
#define
.eqv heap, 0x10040000
.eqv in_buf, 0x10040020 #input buffer
.eqv exc_ptr, 0x80000180
.eqv stop,20
#.eqv newLn,0xa
#macros
.macro _done
li $v0, 10 #stop code
syscall #stop
.end_macro 
.macro _print_str (%str)
la $a0, %str
li $v0, 4
syscall
.end_macro
.macro _GUI_out (%str)
la $a0, %str
li $v0, 55 #GUI msg code
li $a1, 1 #msg type is info
syscall
.end_macro
.macro _print_int(%reg)
move $a0,%reg
#lw $a0,(%reg)
li $v0,1 #int
syscall
_newline
.end_macro
.macro _GUI_in(%prompt) #a0=int, a1=status code
li $v0, 51 #int read
la $a0,%prompt
syscall
beqz $a1, no_error
_print_str(Err_msg2)
_GUI_out(Err_msg2)
b loop_main
no_error:
.end_macro
.macro _newline
li $a0, 0xa
li $v0, 11
syscall
.end_macro
#**ISR macro->Trap
.macro _ISR (%str)
_print_str(%str)
_GUI_out(%str)
Teq $0,$0 #Trap: simulate INT<-1 (in ktext)
b loop_main
.end_macro
#code
.text
#saves: $s0=Int nbr, $s1=vector nbr
#$t9=stop counter
li $t9,stop
La $a0, title
Jal printStr
#--main Loop--
loop_main:
   subiu $t9,$t9,1 #decr counter
   bltz $t9,Stop
   _GUI_in(prompt1) #get Type in $a0
   move $s0,$a0 #save Type in $s0
   #Int TYPE Branch table (if-case)
   beq $s0,0,NMI
   beq $s0,1,NVI
   beq $s0,2,VI
   beq $s0,9,Halt
   b Err #none of above
   NMI: _ISR(NMI_str)
   NVI: _ISR(NVI_str)
   VI: 	#get vector
      _GUI_in(prompt2) #get vector in $a0
      move $s1,$a0 #save vector in $s1
      _ISR(VI_str)
      
   Halt: #Quit
   _print_str(Halt_msg)
   _GUI_out(Halt_msg)
   _done #**exit program**
   
   Err: #default
   _GUI_out(Err_msg1)
   _print_str(Err_msg1)
   b loop_main
   
   Stop:
   _GUI_out(Stop_msg)
   _print_str(Stop_msg)
   _done #**alt exit-stopped out
   #end table
#--END main Loop--
_done #end of main code
##subroutines follow**
#print $a0 on console
printStr:
li $v0, 4
syscall
jr $ra
#OUTput GUI msg
GUI_out: #ptr in $a0
li $v0, 55 #GUI msg code
li $a1, 1 #msg type is info
syscall
jr $ra
#INput GUI msg
GUI_in: #a0=int, a1=status code
li $v0, 51 #int read
syscall
bltz $a1, in_error
jr $ra
in_error:
  _GUI_out(Err_msg2)
  li $a0, 5
jr $ra
#--end subs--
#**start handler code in kernel seg**
.macro _push_k
move $k0, $a0 #save regs
move $k1, $a1
.end_macro
.macro _pop_k
move $a0, $k0 #restore regs
move $a1, $k1
.end_macro
#.macro _print_all (%str)

.kdata
kmsg: .asciiz " ...starting Interrupt handler for: "
.align 2
def_msg: .asciiz "Warning: unimplemented vector\n"
.align 2
vgenStr: .asciiz "now handling the "
.align 2
v0Str: .asciiz "keyboard\n"
.align 2
v1Str: .asciiz "mouse\n"
.align 2
EC_str: .asciiz "Exception code="
.align 2
end_Kdata: .asciiz "&&&&$$$$"

#saves: $s0=Int code,$s1=vector,$s2=EC
.ktext exc_ptr
#save state
_push_k
_print_str(kmsg) #prt msg via macro
#bump EPC
mfc0 $t0,$14
addi $t0,$t0,4 #incr RA in EPC
mtc0 $t0,$14 #EPC+4 (for ERET)

#--INT Branch Table--
Beq $s0, 0, NMI_handler
Beq $s0, 1, NVI_handler
#else VI
_print_str(VI_str)
_print_str(Vect_str)
_print_int($s1)
#print "now handling..."
_print_str(vgenStr)
#--Vector Branch Table--
Beq $s1, 0, v0
Beq $s1, 1, v1
Beq $s1, 2, v2
Beq $s1, 3, v3
#default
b default
#end Br table
#start ISR's
NMI_handler:
   _print_str(NMI_str)
   b EC
NVI_handler:
   _print_str(NVI_str)
   b EC
#--Vector Table-- 
#print I/O device name & don't fall thru
v0: _print_str(v0Str)
   b EC
#popup?
v1: _print_str(v1Str)
   b EC
v2:
v3:
default: #un-impl
_print_str(def_msg)
#--end Table
#Exc Code: extract $s2=EC, print it
EC: #extract the Exc code
mfc0 $t5,$13
srl $t5,$t5,2
andi $s2,$t5,0x1f #11111
#print EC
_print_str(EC_str)
_print_int($s2)
b return
#parse exception (extra)
Beq $s2,0,Int_handler
Beq $s2,8,Syscall_handler
Beq $s2,13,Trap_handler #SW Int
#Other Exceptions (not handled here)
#start Int/Trap handlers--place holders
Int_handler:
Syscall_handler:
Trap_handler:
#no action, print default
#_print_str(def_msg)
#_pop_k, eret
return:
   _pop_k
   eret
#--end ISR's--
#--NO subs--
#--end of program--#
