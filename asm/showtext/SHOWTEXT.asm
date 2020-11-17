.286
.model small,stdcall
include showtext.inc
.code
drawChar proc,location:WORD,char:BYTE,color:BYTE
	push si
	push di
	push bx
	push dx
	push es
	mov ax,darwadd
	mov es,ax
	mov si,location
	mov ax,(COORD ptr [si]).Y
	mov bx,80
	mul bx
	add ax,(COORD ptr [si]).X
	shl ax,1
	mov di,ax
	mov al,BYTE ptr char
	stosb
	mov al,BYTE ptr color
	stosb
	pop es
	pop dx
	pop bx
	pop di
	pop si
	ret
drawChar endp
end
