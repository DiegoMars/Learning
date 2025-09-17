        .text
        .global _start

_start:
        MOV     R0, #72         @ Initialize 72

        SUB     R7, R0, #7      @ 1st sub 7
        ADD     R6, R6, #1      @ Add 1 to quotient
        SUB     R7, R7, #7      @ 2nd sub 7
        ADD     R6, R6, #1      @ Add 1 to quotient
        SUB     R7, R7, #7      @ 3rd sub 7
        ADD     R6, R6, #1      @ Add 1 to quotient
        SUB     R7, R7, #7      @ 4th sub 7
        ADD     R6, R6, #1      @ Add 1 to quotient
        SUB     R7, R7, #7      @ 5th sub 7
        ADD     R6, R6, #1      @ Add 1 to quotient
        SUB     R7, R7, #7      @ 6th sub 7
        ADD     R6, R6, #1      @ Add 1 to quotient
        SUB     R7, R7, #7      @ 7th sub 7
        ADD     R6, R6, #1      @ Add 1 to quotient
        SUB     R7, R7, #7      @ 8th sub 7
        ADD     R6, R6, #1      @ Add 1 to quotient
        SUB     R7, R7, #7      @ 9th sub 7
        ADD     R6, R6, #1      @ Add 1 to quotient
        SUB     R7, R7, #7      @ 10th sub 7
        ADD     R6, R6, #1      @ Add 1 to quotient

        SWI     0x6b            @ Print integer in R0
        SWI     0x02            @ Exit program
