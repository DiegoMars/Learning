        .text
        .global _start

_start:
                                @ Numbers can only be 0-255 with MOV
                                @ Use LDR to use bigger numbers
        LDR     R0, =9999       @ First number
        LDR     R1, =10000      @ Second number
        ADD     R2, R0, R1      @ R2 = R0 + R1

        MOV     R0, #100        @ Make R0 100 as the default value?
        ADD     R0, R0, #2      @ 1
        ADD     R0, R0, #2      @ 2
        ADD     R0, R0, #2      @ 3
        ADD     R0, R0, #2      @ 4
        ADD     R0, R0, #2      @ 5
        ADD     R0, R0, #2      @ 6
        ADD     R0, R0, #2      @ 7
        ADD     R0, R0, #2      @ 8
        ADD     R0, R0, #2      @ 9
        ADD     R0, R0, #2      @ 10
        MOV     R7, R0          @ Final move

        SWI     0x6b            @ Print integer in R0
        SWI     0x02            @ Exit program
