[SECTION .data] ;数据段
ALIGN 16
[BITS 16]
LABEL_DATA:
szMessage0: db "INT 15h,Function Code:0E801h - Get Memory Size for large configurations.",0ah,0dh,'$'
szMessage1: db "Memory check failed.",0ah,0dh,'$'
szMessage2: db "Memory check succeed.",0ah,0dh,"AX = Extended 1: "
szExtended1: db "0000h ",0ah,0dh
szMessage3: db "BX = Extended 2: "
szExtended2: db "0000h ",0ah,0dh
szMessage4: db "CX = Configured 1: "
szConfigured1: db "0000h ",0ah,0dh
szMessage5: db "DX = Configured 2: "
szConfigured2: db "0000h ",0ah,0dh,'$'
[SECTION .bss STACK] ;堆栈段
ALIGN 16
[BITS 16]
LABEL_STACK:
	resb 512 
TopOfStack equ $ - LABEL_STACK - 1

[SECTION .code] ;代码段
[BITS 16]
..start:
LABEL_INIT_SEG_REG:
	mov ax,seg LABEL_DATA
	mov ds,ax
	mov es,ax

	mov ax,seg LABEL_STACK
	mov ss,ax
	mov ax,TopOfStack
	mov sp,ax

LABEL_BEGIN:
	mov ah,09h
	mov dx,szMessage0
	int 21h
	mov ax,0E801h
	int 15h
	jc LABEL_MEM_CHK_FAILD
	push ax
	call Hex2ASCII
	mov word [szExtended1 + 2],ax
	pop ax
	shr ax,8
	call Hex2ASCII
	mov word [szExtended1],ax
	mov ax,bx
	call Hex2ASCII
	mov word [szExtended2 + 2],ax
	mov al,bh
	call Hex2ASCII
	mov word [szExtended2],ax
	mov ax,cx
	call Hex2ASCII
	mov word [szConfigured1 + 2],ax
	mov al,ch
	call Hex2ASCII
	mov word [szConfigured1],ax
	mov ax,dx
	call Hex2ASCII
	mov word [szConfigured2 + 2],ax
	mov al,dh
	call Hex2ASCII
	mov word [szConfigured2],ax
	mov ah,09h
	mov dx,szMessage2
	int 21h
	jmp LABEL_END

LABEL_MEM_CHK_FAILD:
	mov ah,09h
	mov dx,szMessage1
	int 21h

LABEL_END:
	mov ax,04c00h
	int 21h

Hex2ASCII:
	push edx
	mov dl,al
	shr dl,4
	add dl,030h
	cmp dl,'9'
	jbe .next1
	add dl,7
.next1:
	mov ah,dl
	mov dl,al
	and dl,0fh
	add dl,030h
	cmp dl,'9'
	jbe .next2
	add dl,7
.next2:
	mov al,dl
	xchg ah,al
	pop edx
	ret

