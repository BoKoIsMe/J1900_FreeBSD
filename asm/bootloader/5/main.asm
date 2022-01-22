LOAD			equ 07c00h
EXEC			equ 0600h
MAGIC			equ 0aa55h
SIZE_MBR		equ 512
DISP_BASE		equ 0B800h
DISP_MODE		equ 0002h
DISP_COLOUR		equ 0ch

	org LOAD
start:
	mov ax,cs
	mov ds,ax
	mov es,ax
	mov ss,ax
	mov fs,ax
	mov sp,07c00h
	mov di,(main - start) + EXEC
	mov si,main
	mov cx,SIZE_MBR - (main - start)
	rep movsb
	mov ax,cs
	mov [$ + 6],ax
	jmp 0:(main - start) + EXEC
main:
	mov ax,DISP_BASE
	mov es,ax
	xor di,di
	mov si,(hwMSG - start) +EXEC
	mov ax,DISP_MODE
	int 10h
	mov cx,lenMSG
	mov al,DISP_COLOUR
	cld
again:
	movsb
	stosb
	loop again
	jmp $
hwMSG db "Hello, OS world!"
lenMSG equ $ - hwMSG
times 510 - ($ - $$) db 0
dw MAGIC

