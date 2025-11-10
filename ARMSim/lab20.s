        .text
        .global _start

_start:

        BL      FILL
        BL      COPY
        HERE:
        B       HERE

	;@----- Fill Subroutine
        FILL:
        LDR     R0,=0x55AA55AA
        LDR     R9,=0x1000
        STR     R0,[R9]
        BX LR
	;@----- END of Fill Subroutine

        ;@----- Copy Subroutine
        COPY:
        LDR     R1,[R9]
        LDR     R9,=0x10000
        STR     R1,[R9]
        ;@----- END of Copy Subroutine


        SWI     0x6b            @; Print integer in R0
        SWI     0x02            @; Exit program
