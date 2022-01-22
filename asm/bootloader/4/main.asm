	org 07c00h
	mov ax,cs
	mov ds,ax
	mov ss,ax
	mov fs,ax
	mov sp,07c00h
	mov ax,0B800h
	mov es,ax
	xor di,di
	mov si,hwMSG
	mov ax,0002h
	int 10h
	mov cx,lenMSG
	mov al,0ch
	cld
again:
	movsb
	stosb
	loop again
	jmp $
hwMSG db "Hello, OSS world!"
lenMSG equ $ - hwMSG
times 510 - ($ - $$) db 0
dw 0xaa55

