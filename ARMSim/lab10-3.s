        .text
        .global _start

_start:
        @; Part 3
        @; Will be using 4 variables for this. 2 for first (R0) and second (R2)
        @; nums, one for memory address (R9), and one for the counter (R3)
        MOV     R0,#0           @; Initialized first num
        MOV     R2,#1           @; Initialized second num
        MOV     R3,#8           @; Counter to 8
        LDR     R9,=0x10000     @; Initialize memory address

        STR     R0,[R9]         @; Writing R0 to memory location 0x10000
        ADD     R9,R9,#0x4      @; Move 4 memory locations over
        STR     R2,[R9]         @; Writing R2 to memory location 0x10004
        FLOOP:
        LDR     R2,[R9]         @; Load F(n-1) number
        SUB     R9,R9,#4        @; Move 4 memory locations back
        LDR     R0,[R9]         @; Load F(n-2) number
        ADD     R9,R9,#8        @; Move 8 memory locations forward
        ADD     R0,R0,R2        @; Add F(n-1) and F(n-2) nums, and temporarily 
                                @; put it in R0
        STR     R0,[R9]         @; Storing R0 into the F(n) memory location
        SUBS    R3,R3,#1        @; Subtracting from counter
        BNE     FLOOP           @; Loop back to FLOOP if counter isn't 0

        SWI     0x6b            @; Print integer in R0
        SWI     0x02            @; Exit program
