        .text
        .global _start

_start:
	@; Part 1
        LDR	R0, =0x80000000	@; Initializes the 32 bit to one
	MOV	R1, #31		@; Initialize counter
	LLOOP:
	LSR	R0, R0, #1	@; Logical shift right once
	SUBS	R1, R1, #1	@; Subtract one from countre
	BNE	LLOOP		@; Loop back if R1 != 0

	@; Part 2
	LDR	R9, =1000	@; Initialize memory location
	MOV	R2, #1		@; Initialize odd numbers
	MOV	R1, #11		@; Initizlize counter
	SUBS	R1, R1, #1	@; Subtract one from counter
	OLOOP:
	STRB 	R2, [R9]	@; Store odd number into memory
	ADD	R9, R9, #1	@; Add one to memory location
	ADD	R2, R2, #2	@; Add 2 to odd number to get next one
	SUBS	R1, R1, #1	@; Subtract one from counter
	BNE	OLOOP		@; Loop back if counter != 0

        SWI     0x6b
        SWI     0x02
