foreGroundBlack		EQU 0
foreGroundBlue		EQU 00000001B
foreGroundGreen		EQU 00000010B
foreGroundRed		EQU 00000100B
foreGroundCyan		EQU 00000011B
foreGroundPurple	EQU 00000101B
foreGroundYellow	EQU 00000110B
foreGroundWhite		EQU 00000111B
highlight			EQU 00001000B
backGroundBlack		EQU 0
backGroundBlue		EQU 00010000B
backGroundGreen		EQU 00100000B
backGroundRed		EQU 01000000B
backGroundCyan		EQU 00110000B
backGroundPurple	EQU 01010000B
backGroundYellow	EQU 01100000B
backGroundWhite		EQU 01110000B
blink				EQU 10000000B
darwadd				EQU 0B800h

COORD STRUCT
	X WORD ?
	Y WORD ?
COORD ENDS
