        .text
        .global _start

_start:
        BL      WRITE

        MOV     R0,#0           @; Sum
        MOV     R1,#20          @; Counter
        MOV     R2,#0           @; Temp stored
        LDR     R8,=0x11000     @; Write memory location
        LDR     R9,=0x10000     @; Read memory location
        SUMMATION_LOOP:
                BL      COPY
                BL      SUM
                ADD     R9,R9,#1
                SUBS    R1,R1,#1
                BNE     SUMMATION_LOOP

        HERE:
        B       HERE

	;@----- Write Subroutine
        WRITE:
	MOV	R0,#1           @; Numbers to add
	MOV	R2,#20          @; Counter
	LDR	R9,=0x10000     @; Memory Location
        WRITE_LOOP:
                STRB    R0,[R9]         @; Store number to memory location
                ADD     R0,R0,#1        @; Increase numbers by one
                ADD     R9,R9,#1        @; Increase memory location by one
                SUBS    R2,R2,#1        @; Decrease counter by one
                BNE     WRITE_LOOP      @; Loop till counter = 0

	MOV	R0,#0           @; Clean up
	MOV	R2,#0           @; Clean up
	MOV	R9,#0           @; Clean up
        BX LR
	;@----- END of Write Subroutine

        ;@----- Copy Subroutine
        COPY:
        LDRB    R2,[R9]
        BX LR
        ;@----- END of Copy Subroutine

        ;@----- Sum Subroutine
        SUM:
        ADD     R0,R0,R2        @; Add temp add to sum
        STR     R0,[R8]
        BX LR
        ;@----- END of Sum Subroutine

        SWI     0x6b          @; Print integer in R0
        SWI     0x02          @; Exit program
