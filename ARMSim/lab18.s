        .text
        .global _start

_start:
	LDR	R0,=0b11111111	@; Initialize inputs
	MOV	R1,#6		@; Initialize selectors
	MOV	R2,#0		@; Initialize output
	MOV	R9,#0		@; Checker thing

	CMP	R1,#1		@; Z=1 if selector = 1
	BNE	SKIP1		@; Skip if Z = 0
	AND	R9,R0,#0b1	@; Mask input 1
	MOV	R2,R9		@; Output = input 1
	SKIP1:

	CMP	R1,#2		@; Z=1 if selector = 2
	BNE	SKIP2		@; Skip if Z = 0
	AND	R9,R0,#0b10	@; Mask input 2
	MOV	R2,R9		@; Output = input 2
	SKIP2:

	CMP	R1,#3		@; Z=1 if selector = 3
	BNE	SKIP3		@; Skip if 0
	AND	R9,R0,#0b100	@; Mask input 3
	MOV	R2,R9		@; Output = input 3
	SKIP3:

	CMP	R1,#4		@; Z=1 if selector = 4
	BNE	SKIP4		@; Skip if 0
	AND	R9,R0,#0b1000	@; Mask input 4
	MOV	R2,R9		@; Output = input 4
	SKIP4:

	CMP	R1,#5		@; Z=1 if selector = 5
	BNE	SKIP5		@; Skip if 0
	AND	R9,R0,#0b10000	@; Mask input 5
	MOV	R2,R9		@; Output = input 5
	SKIP5:

	CMP	R1,#6		@; Z=1 if selector = 6
	BNE	SKIP6		@; Skip if 0
	AND	R9,R0,#0b100000	@; Mask input 6
	MOV	R2,R9		@; Output = input 6
	SKIP6:

	CMP	R1,#7		@; Z=1 if selector = 7
	BNE	SKIP7		@; Skip if 0
	AND	R9,R0,#0b1000000@; Mask input 7
	MOV	R2,R9		@; Output = input 7
	SKIP7:

	CMP	R1,#8		  @; Z=1 if selector = 8
	BNE	SKIP8		  @; Skip if 0
	AND	R9,R0,#0b10000000 @; Mask input 8
	MOV	R2,R9		  @; Output = input 8
	SKIP8:

        SWI     0x6b            @; Print integer in R0
        SWI     0x02            @; Exit program
