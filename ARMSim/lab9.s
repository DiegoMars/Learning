        .text
        .global _start

_start:
        @ Step 1
        LDR     R0, =0x12345678 @ Initialize R0
        LDR     R1, =0x87654321 @ Initialize R1
        LDR     R9, =0x1000     @ Initialize memory location
        ADD     R2, R0, R1      @ Add R1 & R2
        STR     R2, [R9]        @ Store R2 in Memory Location

        @ Step 2
        LDR     R0, =0xFFFFFFFF @ Initialize R0
        LDR     R1, =0xFFEEDDCC @ Initialize R1
        LDR     R9, =0x10000    @ Initialize memory location
        SUB     R3, R0, R1      @ Subtract R1 & R2
        STR     R3, [R9]        @ Store R2 in Memory Location

        @ Step 3
        LDR     R9, =0x1000C    @ Initialize memory location
        LDRH    R7, [R9]        @ Load half word into R7

        @ Step 4
        LDR     R9, =0x1000C    @ Initialize memory location
        LDRB    R6, [R9]        @ Load byte into R6

        @ Step 5
        LDR     R9, =0x1000C    @ Initialize memory location
        LDR     R5, [R9]        @ Load half word into R7

        SWI     0x6b            @ Print integer in R0
        SWI     0x02            @ Exit program
