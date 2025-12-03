_start:
.global _start
	
	MOV	R0,#0		;@ State register: ped button, Q1, Q0
				;@ Red: 0, Yellow: 1, Green: 2
	MOV	R1,#1		;@ Ped button input
	MOV	R2,#5		;@ Counter
	MLOOP:
		BL	STATE_SWITCH
		EOR	R1,R1,#1	@; Toggle ped switch
		SUBS	R2,R2,#1
		BNE	MLOOP

	B	END

;@-------------------------------------------
STATE_RED:
        PUSH    {LR}		;@ Save return address
	BL	SHORT_DELAY	;@ Long delay
	BIC	R0,#3		;@ Clears Q1, Q0
	EOR	R0,R0,#2	;@ Sets state 2 or green
	POP	{LR}		;@ Restore LR
        BX      LR		;@ Return

STATE_GREEN:
        PUSH    {LR}		;@ Save return address
	BL	PED_BUTTON	;@ check for button press
	AND	R7,#0b100	;@ Mask ped button state
	EORS	R6,R7,#0	;@ Checking if state = 1
	BNE	gped_skip
	BL	SHORT_DELAY	;@ Yes: Short delay
	BL	green_end
	gped_skip:
	BL	LONG_DELAY	;@ No: Long Delay

	green_end:
	BIC	R0,#3		;@ Clears Q1, Q0
	EOR	R0,R0,#1	;@ Sets state 1 or yellow
	POP	{LR}		;@ Restore LR
        BX      LR		;@ Return

STATE_YELLOW:
        PUSH    {LR}		;@ Save return address
	BL	SHORT_DELAY	;@ Short delay
	BIC	R0,#3		;@ Clears Q1, Q0
	EOR	R0,R0,#0	;@ Sets state 0 or red
	POP	{LR}		;@ Restore LR
        BX      LR		;@ Return

STATE_SWITCH:
        PUSH    {LR}		;@ Save return address
	AND	R7,R0,#0b11	;@ Mask state

        EORS    R6,R7,#0        ;@ Checking if in state 0, or red
        BNE     ys_skip         ;@ If no zero flag, skip to next state test
	BL	STATE_RED	;@ Go to state red
	POP	{LR}		;@ Restore LR
        BX      LR		;@ Return

	ys_skip:
        EORS    R6,R7,#1        ;@ Checking if in state 1, or yellow
        BNE     gs_skip         ;@ If no zero flag, skip to next state test
	BL	STATE_YELLOW	;@ Go to state yellow
	POP	{LR}		;@ Restore LR
        BX      LR		;@ Return

	gs_skip:
        EORS    R6,R7,#2        ;@ Checking if in state 2, or green
        BNE     os_skip         ;@ If no zero flag, skip to next state test
	BL	STATE_GREEN	;@ Go to state yellow
	POP	{LR}		;@ Restore LR
        BX      LR		;@ Return

	os_skip:
	POP	{LR}		;@ Restore LR
        BX      LR		;@ Return

PED_BUTTON:
        PUSH    {LR}		;@ Save return address
	CMP	R1,#1		;@ Z = 1 if ped button input = 1
	BNE	PSKIP		;@ If Z = 0, skip
	ORR	R0,#0b100	;@ Ped button state = 1
	POP	{LR}		;@ Restore LR
        BX      LR		;@ Return
	PSKIP:
	BIC	R0,#0b100	;@ Ped button state = 0
	POP	{LR}		;@ Restore LR
        BX      LR		;@ Return

;@-------------------------------------------
SHORT_DELAY:
	;@ 2 second delay
        PUSH    {LR}		;@ Save return address
	LDR     R9,=300000
	SD_AGAIN:
		SUBS    R9,R9,#1
		BNE     SD_AGAIN
	POP	{LR}		;@ Restore LR
	BX	LR

LONG_DELAY:
        PUSH    {LR}		;@ Save return address
	MOV	R8,#6
	LD_AGAIN:
		BL	SHORT_DELAY
		SUBS	R8,R8,#1
		BNE	LD_AGAIN
	POP	{LR}		;@ Restore LR
	BX	LR

END:
        SWI     0x6b            ;@ Print integer in R0
        SWI     0x02            ;@ Exit program
