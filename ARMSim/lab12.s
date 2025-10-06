        .text
        .global _start

_start:
	MOV	R0,#0x7		@; Initializing X
	LDR	R1,=0x70000000	@; Initializing Y
	LDR	R9,=0x10000	@; Initializing memory location

	@; Step 1
	LSL	R8,R0,#10	@; Shift X left 10 times
	STR	R8,[R9]		@; Store R8 into memory location

	@; Step 2
	LDR	R9,=0x10004	@; Initializing memory location
	LSR	R8,R1,#12	@; Shift Y right 12 times
	STR	R8,[R9]		@; Store R8 into memory location

	@; Step 3
	LDR	R9,=0x10008	@; Initializing memory location
	LSR	R8,R1,#31	@; Shift X right 31 times
	STR	R8,[R9]		@; Store R8 into memory location

	@; Step 4
	LDR	R2,=0x80000065	@; Initializing Z
	ASR	R8,R2,#5	@; Shift Z right 5 times

	@; Step 5
	LDR	R3,=2024	@; Store 2024 into R3
	LSR	R8,R3,#5	@; Shift 2024 right 5 times, to divide by 2^5

	@; Step 6
	MOV	R4,#16		@; Store 16 into R3
	LSL	R8,R4,#6	@; Shift 16 left 6 times to multiply by 2^6

        SWI     0x6b
        SWI     0x02
