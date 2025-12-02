_start:
.global _start

        MOV     R0,#0           ;@ The first 5 bits are as follows: Y, X, Q2, Q1, Q0
                                ;@ Input works by toggling the X bit and run the switch subroutine
        EOR     R0,R0,#8        ;@ Toggles the X bit
        BL      switch          ;@ Run switch
        EOR     R0,R0,#8        ;@ Toggles the X bit
        BL      switch          ;@ Run switch
        EOR     R0,R0,#8        ;@ Toggles the X bit
        BL      switch          ;@ Run switch
        BL      switch          ;@ Run switch
        EOR     R0,R0,#8        ;@ Toggles the X bit
        BL      switch          ;@ Run switch

        B       done            ;@ Program end

;@-------------------------------------------
switch:
        AND     R9,R0,#7        ;@ Masks state
        AND     R8,R0,#8        ;@ Masks input

        EORS    R7,R9,#0        ;@ Checking if in state 0
        BNE     state1          ;@ If no zero flag, skip to next state test
        BIC     R0,R0,#0b10111  ;@ Clear state and output
        EORS    R7,R8,#8        ;@ Checking if input = 1
        BNE     state00         ;@ If no zero flag, run input 0 code
        ORR     R0,R0,#0b00000  ;@ Set state and output
        BX      LR
        state00:
        ORR     R0,R0,#0b00001  ;@ Set state and output
        BX      LR              ;@ Return

        state1:
        EORS    R7,R9,#1        ;@ Checking if in state 1
        BNE     state2          ;@ If no zero flag, skip to next state test
        BIC     R0,R0,#0b10111  ;@ Clear state and output
        EORS    R7,R8,#8        ;@ Checking if input = 1
        BNE     state10         ;@ If no zero flag, run input 0 code
        ORR     R0,R0,#0b00010  ;@ Set state and output
        BX      LR
        state10:
        ORR     R0,R0,#0b00001  ;@ Set state and output
        BX      LR              ;@ Return

        state2:
        EORS    R7,R9,#2        ;@ Checking if in state 2
        BNE     state3          ;@ If no zero flag, skip to next state test
        BIC     R0,R0,#0b10111  ;@ Clear state and output
        EORS    R7,R8,#8        ;@ Checking if input = 1
        BNE     state20         ;@ If no zero flag, run input 0 code
        ORR     R0,R0,#0b00011  ;@ Set state and output
        BX      LR
        state20:
        ORR     R0,R0,#0b00001  ;@ Set state and output
        BX      LR              ;@ Return

        state3:
        EORS    R7,R9,#3        ;@ Checking if in state 3
        BNE     state4          ;@ If no zero flag, skip to next state test
        BIC     R0,R0,#0b10111  ;@ Clear state and output
        EORS    R7,R8,#8        ;@ Checking if input = 1
        BNE     state30         ;@ If no zero flag, run input 0 code
        ORR     R0,R0,#0b00000  ;@ Set state and output
        BX      LR
        state30:
        ORR     R0,R0,#0b00100  ;@ Set state and output
        BX      LR              ;@ Return

        state4:
        EORS    R7,R9,#4        ;@ Checking if in state 4
        BNE     state5          ;@ If no zero flag, skip to next state test
        BIC     R0,R0,#0b10111  ;@ Clear state and output
        EORS    R7,R8,#8        ;@ Checking if input = 1
        BNE     state40         ;@ If no zero flag, run input 0 code
        ORR     R0,R0,#0b10000  ;@ Set state and output
        BX      LR
        state40:
        ORR     R0,R0,#0b10001  ;@ Set state and output
        BX      LR              ;@ Return

        state5:
        BX      LR              ;@ Return

done:
        B       done            ;@ Endless loop (stop here)
