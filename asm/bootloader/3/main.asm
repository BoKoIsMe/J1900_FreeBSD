LOAD		equ 07c00h
EXEC		equ 0600h
PT_OFF		equ 01beh
MAGIC		equ 0aa55h
FL_PACKET	equ 080h

NHRDRV		equ 0475h
	org LOAD
start:
	cld
	xor ax,ax
	mov es,ax
	mov ds,ax
	mov ss,ax
	mov sp,LOAD

	mov di,main-EXEC+LOAD
	mov si,main
	mov cx,0200h - (main-start)
	rep movsb
	;jmp main-EXEC+LOAD
	jmp 0000:0F21Ch

main:
	mov ax,cs
	mov ds,ax
	mov es,ax
	call DispStr
	jmp $
DispStr:
	mov ax,BootMessage-EXEC+LOAD
	mov bp,ax
	mov cx,16
	mov ax,01301h
	mov bx,000ch
	mov dl,0
	int 10h
	ret
BootMessage: db "Hello, OS world!"
times 510 - ($ - $$) db 0
dw MAGIC

