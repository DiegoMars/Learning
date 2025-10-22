        .text
        .global _start

_start:
        MOV     R0, #0xFF       @; Initializing R0
        MOV     R1, #0xA5       @; Initializing R1
        MOV     R2, #0xCC       @; Initializing R2
        MOV     R8, R0          @; Biggest num
        LDR     R9, =0x1000     @; Initializing memory location

        CMP     R8, R1          @; See which is bigger
        BCS     SKIPO           @; Skip if R8 > R1
        MOV     R8, R1          @; Otherwise make R8 = R3
        SKIPO:

        CMP     R8, R2          @; See which is bigger
        BCS     SKIPS           @; Skip if R8 > R2
        MOV     R8, R2          @; Otherwise make R8 = R2
        SKIPS:

        STR     R8, [R9]        @; Store largest into memory location R9

        SWI     0x6b            @; Print integer in R0
        SWI     0x02            @; Exit program
