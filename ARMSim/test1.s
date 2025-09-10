        .text
        .global _start

_start:
        MOV     R0, #5        @ First number
        MOV     R1, #7        @ Second number
        ADD     R2, R0, R1    @ R2 = 5 + 7

        SWI     0x6b          @ Print integer in R0
        SWI     0x02          @ Exit program