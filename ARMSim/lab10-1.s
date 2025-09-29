        .text
        .global _start

_start:
        @; Part 1
        LDR     R1,=0xFF        @; Initialize R1
        MOV     R2,#15          @; Initialize counter
        BACK:
        ADD     R1,R1           @; Add R1 into itself
        SUBS    R2,R2,#1        @; Subtract from counter
        BNE     BACK            @; Loop back to BACK if counter isn't 0

        SWI     0x6b            @; Print integer in R0
        SWI     0x02            @; Exit program
