_start:
.global _start

@  -----------------------------
@  Registers
@  R0 = current state
@  R1 = pointer to input key
@  R2 = input key
@  R3 = 1 if the lock is open
@ -----------------------------

START:
        MOV R0, #0          @  Initial state = LOCKED
        LDR R1, =INPUT      @  Initialize the pointer to memory location which keeps the input 
                            @  keys

MAIN_LOOP:


             @Check if the current state is STATE0, 
             @Go to STATE0 if current state is STATE0  

             @Check if the current state is STATE1, 
             @Go to STATE1 if current state is STATE1  

             @Check if the current state is STATE3,
             @Go to STATE2 if current state is STATE2  

             @Check if the current state is STATE4,
             @Go to STATE3 if current state is STATE3  

             @Check if the current state is UNLOCKED,
             @Go to UNLOCKED current state is UNLOCKED  

@  -----------------------------
STATE0:          @LOCKED (Initial)State
                            @Read the first key from the memory
                            @check to see if the key entered is 1
                            @  correct → next state
                            @  wrong → stay locked
        B MAIN_LOOP
@  -----------------------------
STATE1:
                           @Increment the pointer to memory location to get the next key
                           @Read the second key from the memory
                           @check to see if the key entered is 2
            
        
        B MAIN_LOOP
@  -----------------------------
STATE2:
                           @Increment the pointer to memory location to get the next key
                           @Read the third key from the memory
                           @check to see if the key entered is 3
            
            
        B MAIN_LOOP 
@  -----------------------------
STATE3:
                          @Increment the pointer to memory location to get the next key
                          @Read the fourth key from the memory
                          @check to see if the key entered is 4
       
       
        B MAIN_LOOP

@  -----------------------------
UNLOCKED:
        @  Add code to represent "door open"
       
        B UNLOCKED

@  -----------------------------
INPUT:   .byte 1,2,3,4     @  Change this to test: 1, 2, 3, 4 etc.
        .data
        