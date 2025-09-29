        .text
        .global _start

_start:
        @; Part 2
        LDR     R0,=0x0         @; Initialize R0, or a
        MOV     R1,#50          @; Initialize R1, or b
        MOV     R2,#15          @; Initialize counter i
        ILOOP:
        MOV     R3,#100         @; Initialize counter j
        JLOOP:
        ADD     R0,R1,R0        @; Add a and b, then set it as a
        SUBS    R3,R3,#1        @; Subtract from counter j
        BNE     JLOOP           @; Loop back to JLOOP if counter j isn't 0
        SUBS    R2,R2,#1        @; Subtract from counter i
        BNE     ILOOP           @; Loop back to ILOOP if counter i isn't 0

        SWI     0x6b            @ Print integer in R0
        SWI     0x02            @ Exit program
