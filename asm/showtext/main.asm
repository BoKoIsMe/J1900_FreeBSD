.286
.model small,stdcall
include showtext.inc
includelib showtext.lib

drawChar proto,location:WORD,char:BYTE,color:BYTE

.data
	currentPosition COORD <0,0>
	szString db "Welcom to the ASM world.",0dh,0ah,0
	LENSTRING EQU $ - szString
.stack 200h

.code
.startup
	push ds
	pop es
	mov ah,0002h
	int 10h
	mov ax,10
	mov currentPosition.X,ax
	mov ax,12
	mov currentPosition.Y,ax
	mov si,offset szString
	mov cx,LENSTRING - 3
@@:
	invoke drawChar,offset currentPosition,[si],foreGroundYellow or highlight or backGroundBlue
	inc currentPosition.X
	.IF currentPosition.X == 79
		mov currentPosition.X,0
		inc currentPosition.Y
	.ENDIF
	.IF currentPosition.Y == 24
		mov currentPosition.Y,0
	.ENDIF
	inc si
	loop @B
.exit
end
