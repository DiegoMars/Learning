
_start:
.global _start

	LDR	R0,=0x10000	;@ Initialized memory address
	MOV	R1,#10		;@ Initialized counter

	MOV	R2,#1		;@ Seed 2
	PUSH	{R2}		;@ Add to stack
	MOV	R2,#0		;@ Seed 1
	PUSH	{R2}		;@ Add to stack

LOOP:
	BL	calc_fib
	ADD	R0,R0,#4
	SUBS	R1,R1,#1	;@ Subract 1 from counter
	BNE	LOOP

        B       done

calc_fib:
	MOV	R3,#0		;@ Sum
	POP	{R2}		;@ Grab F_(n-2)
	ADD	R3,R3,R2
	POP	{R2}		;@ Grab F_(n-1)
	ADD	R3,R3,R2	;@ F_n = F_(n-2) + F(n-1)
	STR	R3,[R0]		;@ Storing F_n
	PUSH	{R3}		;@ Pushing F_(n), which will become the new F_(n-1)
	PUSH	{R2}		;@ Pushing F_(n-1), which becomes the new F_(n-2)
        BX      LR

done:
        B       done
