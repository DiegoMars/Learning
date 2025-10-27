        .text
        .global _start

_start:
	

        SWI     0x6b            @; Print integer in R0
        SWI     0x02            @; Exit program
