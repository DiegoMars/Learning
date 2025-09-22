        .text
        .global _start

_start:
        @ Part 1
        LDR     R0, =0x10000    @ Initialize Pointer
        LDR     R2, [R0]        @ Load 0x10000-0x10003 into R2

        ADD     R0, R0, #0x4    @ Move pointer 4 memory locations over
        LDR     R3, [R0]        @ Load 0x10004-0x10007 into R3

        ADD     R0, R0, #0x4    @ Move pointer 4 memory locations over
        LDR     R4, [R0]        @ Load 0x10008-0x1000B into R4

        ADD     R0, R0, #0x4    @ Move pointer 4 memory locations over
        LDR     R5, [R0]        @ Load 0x1000C-0x1000E into R5

        @ Part 2
        LDR     R0, =0x10000    @ Initialize Pointer
        LDR     R1, =0x00000000 @ Empty thing
        STR     R1, [R0]        @ Clear 0x10000-0x10003

        ADD     R0, R0, #0x4    @ Move pointer 4 memory locations over
        STR     R1, [R0]        @ Clear 0x10004-0x10007

        ADD     R0, R0, #0x4    @ Move pointer 4 memory locations over
        STR     R1, [R0]        @ Clear 0x10008-0x1000B

        ADD     R0, R0, #0x4    @ Move pointer 4 memory locations over
        STR     R1, [R0]        @ Clear 0x1000C-0x1000E

        SWI     0x6b            @ Print integer in R0
        SWI     0x02            @ Exit program

        @ Part 3
        LDR     R0, =0x10000    @ Initialize Pointer
        LDR     R1, =0X01234567 @ Initialize R1
        LDR     R2, =0x89ABCDEF @ Initialize R2
        LDR     R3, =0xABABAB   @ Initialize R3
        LDR     R4, =0xFEDCBA9A @ Initialize R4

        STR     R1, [R0]        @ Store R1 into 0x10000-0x10003

        ADD     R0, R0, #0x4    @ Move pointer 4 memory locations over
        STR     R2, [R0]        @ Store R2 into 0x10004-0x10007

        ADD     R0, R0, #0x4    @ Move pointer 4 memory locations over
        STR     R3, [R0]        @ Store R3 into 0x10008-0x1000B

        ADD     R0, R0, #0x4    @ Move pointer 4 memory locations over
        STR     R4, [R0]        @ Store R4 into 0x1000C-0x1000E
