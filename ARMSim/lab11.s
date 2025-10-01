        .text
        .global _start

_start:
	MOV	R0,#1		@; Initialized GPIO_Port
				@; Bit 0 is button input
				@; Bit 1 is led1 output, 1 is on, 0 is off
				@; Bit 2 is led2 output, 1 is on, 0 is off
        @; Part 1
	@; 1) Check if button (bit 0) is pressed using AND
	@; 2) Turn ON led1 (bit 1) using ORR
	@; 3) Turn ON led2 (bit 2) using EOR
	AND	R1,R0,#1	@; R1 will be 0x1 if the first bit in R0 is 1
	ORR	R0,R0,#2	@; Makes sure that the 2nd bit in R0 is on
	EOR	R0,R0,#4	@; Toggles the 3nd bit, rather than making sure
				@; that it is one

	@; Part 2
	@; R0 is status register:
	@;	Bit 0 is the door sensor (1 for open, 0 for closed)
	@;	Bit 1 is motion detected (1 for detected, 0 for none)
	@;	Bit 2 is authorized key (1 for presente, 0 for absent)
	@; R1 is status register:
	@;	Bit 0 is lock (1 for locked, 0 for unlocked)
	@;	Bit 1 is alarm (1 for ON, 0 for OFF)
	@;	Bit 2 is status LED (toggles every event)
	MOV	R1,#0		@; Clears ragister 1
	MOV	R2,#0		@; Clears register 2, will be my mask
	MOV	R3,#0		@; Clears register 3
	AND	R2,R0,#3	@; Will keep only the 0 and 1 bits
	EORS	R3,R2,#3	@; R3 will be all 0s if bits 0 and 1 are 1 in R2
	BNE	SKIPA		@; Skips to SKIPA if Z=0
	ORR	R1,R1,#2	@; Turns on alarm if R2 if Z=1
	EOR	R1,R2,#4	@; Toggles status LED
	SKIPA:

	AND	R2,R0,#4	@; Keeps only the 2 bit
	EORS	R3,R2,#4	@; R3 will be all 0s if bit 3 is 1 in R2
	BNE	SKIPU		@; If key is not present (Z=0), skip to SKIPU
	BIC	R1,R1,#1	@; Clears bit 0 to unlock the door
	EOR	R1,R2,#4	@; Toggles status LED
	SKIPU:

	MVN	R1,R1		@; Inverts control register

        SWI     0x6b            @; Print integer in R0
        SWI     0x02            @; Exit program
