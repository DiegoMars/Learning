        .text
        .global _start

_start:
        MOV     R0, #10               @ Move number 10 to register R0
        MOV     R0, #25               @ Move number 25 to register R1
        ADD     R2, R0, R1             @ Add two number in R0 and R1 togeter and put the result in R2
        ADD     R2, R0, R2             @ Add content of R0 to R2 and put in R2
        ADD     R3, R1, R2             @ Add content of R1 to R2 and put the result in R3
        ADD     R4, R3, R2             @ Add content of R3 and R2 and put the result in  R4
        MOV     R0, #0                @ clear content of R0
        MOV     R1, #0                @ clear content of R1
        MOV     R2, #0                @ clear content of R2
        MOV     R3, #0                @ clear content of R3

        SWI     0x6b          @ Print integer in R0
        SWI     0x02          @ Exit program
