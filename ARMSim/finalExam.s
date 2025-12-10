_start:
.global _start

;@ -----------------------------
;@  Registers
;@  R0 = current state
;@  R1 = pointer to input key
;@  R2 = input key
;@  R3 = 1 if the lock is open
;@ -----------------------------

START:
        MOV R0, #0          ;@  Initial state = LOCKED
        LDR R1, =INPUT      ;@  Initialize the pointer to memory location which keeps the input 
                            ;@  keys

MAIN_LOOP:
	CMP R0, #0	;@Check if the current state is STATE0, 
	BEQ STATE0	;@Go to STATE0 if current state is STATE0  

	CMP R0, #1	;@Check if the current state is STATE1, 
	BEQ STATE1	;@Go to STATE1 if current state is STATE1  

	CMP R0, #2	;@Check if the current state is STATE2, 
	BEQ STATE2	;@Go to STATE2 if current state is STATE2  

	CMP R0, #3	;@Check if the current state is STATE3, 
	BEQ STATE3	;@Go to STATE3 if current state is STATE3  

	CMP R0, #4	;@Check if the current state is UNLOCKED,
	BEQ UNLOCKED	;@Go to UNLOCKED current state is UNLOCKED  

;@  -----------------------------
STATE0:          ;@LOCKED (Initial)State
	LDRB R2, [R1]	;@Read the first key from the memory
	CMP R2, #1	;@check to see if the key entered is 1
	BNE SKIP0
	MOV R0, #1	;@  correct → next state
        B MAIN_LOOP
	SKIP0:
	MOV R0, #0	;@  wrong → stay locked
        B MAIN_LOOP

;@  -----------------------------
STATE1:
	ADD R1, R1, #1	;@Increment the pointer to memory location to get the next key
	LDRB R2, [R1]	;@Read the second key from the memory
	CMP R2, #2	;@check to see if the key entered is 2
	BNE SKIP1
	MOV R0, #2	;@  correct → next state
        B MAIN_LOOP
	SKIP1:
	MOV R0, #0	;@  wrong → stay locked
        B MAIN_LOOP

;@  -----------------------------
STATE2:
	ADD R1, R1, #1	;@Increment the pointer to memory location to get the next key
	LDRB R2, [R1]	;@Read the second key from the memory
	CMP R2, #3	;@check to see if the key entered is 3
	BNE SKIP2
	MOV R0, #3	;@  correct → next state
        B MAIN_LOOP
	SKIP2:
	MOV R0, #0	;@  wrong → stay locked
        B MAIN_LOOP

;@  -----------------------------
STATE3:
	ADD R1, R1, #1	;@Increment the pointer to memory location to get the next key
	LDRB R2, [R1]	;@Read the second key from the memory
	CMP R2, #4	;@check to see if the key entered is 4
	BNE SKIP3
	MOV R0, #4	;@  correct → next state
        B MAIN_LOOP
	SKIP3:
	MOV R0, #0	;@  wrong → stay locked
        B MAIN_LOOP

;@  -----------------------------
UNLOCKED:
	MOV R3, #1	;@  Add code to represent "door open"
        B UNLOCKED

;@  -----------------------------
INPUT:   .byte 1,1,2,3,4	;@  Change this to test: 1, 2, 3, 4 etc.
        .data
        
