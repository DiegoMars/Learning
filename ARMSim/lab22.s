
_start:
.global _start

        MOV     R0, #5        @ a = 5
        MOV     R1, #7        @ b = 7

        PUSH    {R0, R1}      @ Save a and b on stack

        MOV     R0, #3        @ c = 3
        MOV     R1, #4        @ d = 4

        BL      add_two       @ Call subroutine ? returns (c + d) in R0

        POP     {R1, R2}      @ Restore a ? R1, b ? R2

        ADD     R0, R0, R1    @ R0 = (c+d) + a
        ADD     R0, R0, R2    @ R0 = (c+d+a) + b

        B       done          @ Program end

@-------------------------------------------
@ Subroutine: add_two
@ Input:  R0 = first number
@         R1 = second number
@ Output: R0 = R0 + R1
@-------------------------------------------
add_two:
        PUSH    {LR}          @ Save return address
        ADD     R0, R0, R1    @ R0 = R0 + R1
        POP     {LR}          @ Restore LR
        BX      LR            @ Return

done:
        B       done          @ Endless loop (stop here)
