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
	LDR	R9, =0x1000	@; Initialize memory location
	MOV	R2, #1		@; Initialize odd numbers
	MOV	R1, #10		@; Initizlize counter
	OLOOP:
	STRB  	R2, [R9]	@; Store odd number into memory
	ADD	R9, R9, #1	@; Add one to memory location
	ADD	R2, R2, #2	@; Add 2 to odd number to get next one
	SUBS	R1, R1, #1	@; Subtract one from counter
	BNE	OLOOP		@; Loop back if counter != 0

	@; Part 3
	MOV	R3, #5		@; Tempature 1
	MOV	R4, #6		@; Tempature 2
	MOV	R5, #20		@; Holds threshold
	MOV	R6, #0		@; Will be adding stuff here
	MOV	R7, #0		@; Will be checking flags here
	MOV	R8, #3		@; Initializing status register
				@; Bit 0 for sensor 1
				@; Bit 1 for sensor 2
				@; Bit 2 for alert

	ANDS	R7, R8, #1	@; Masking 0 bit
	BEQ	SKIP		@; If sensor 1 is 0, skip
	ANDS	R7, R8, #2	@; Masking 1 bit
	BEQ	SKIP		@; If sensor 1 is 0, skip
	ADD	R6, R3, R4	@; Adds temp 1 and temp 2
	LSR	R6, R6, #1	@; Logical shift right 1, or dividing by 2
	CMP	R6, R5		@; If result is bigger than threshold, C=1
	BCC	SKIPC		@; If C=0, skip next step
	ORR	R8, R8, #4	@; Sets bit 3 to 1
	SKIPC:
	EOR	R8, R0, #3	@; Set status register to 0 if no error,
				@; otherwise set to 4
	SKIP:

        SWI     0x6b
        SWI     0x02
