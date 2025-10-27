        .text
        .global _start

_start:
        @; Part A
	MOV     R0,#0           @; Initializing X
	MOV     R1,#1           @; Initializing Y
        ADD     R2, R0, R1      @; Doing X + Y
        EOR     R2, R2, #1      @; (X+Y)'

        EOR     R4, R0, #1      @; X'
        EOR     R5, R1, #1      @; Y'
        MOV     R6, #0          @; Since X' times Y' would just be 0

        @; Part B
        MOV     R2, #0
        MOV     R4, #0
        MOV     R5, #0
        MOV     R6, #0          @; Clearing registers

        MOV     R2, #0          @; Since X times Y is 0
        EOR     R2, R2, #1      @; (XY)'

        EOR     R4, R0          @; X'
        EOR     R5, R1          @; Y'
        ADD     R6, R4, R5      @; X' + Y'

        SWI     0x6b            @; Print integer in R0
        SWI     0x02            @; Exit program
