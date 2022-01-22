ORG 0100H
	jmp LABEL_BEGIN

[SECTION .DATA]
ALIGN	16
[BITS	16]
LABEL_DATA:
dwMemSize:			dw 0
ARDStruct:
	dwBaseAddrLow:	dd 0
	dwBaseAddrHigh: dd 0
	dwLengthLow:	dd 0
	dwLengthHigh:	dd 0
	dwType:			dd 0

	szMCFMessage:	db "Memory check failed.",0Ah,0Dh,'$'
	szMCRMessage:	db "Memory check okey.",0Ah,0Dh,'$'
	
[SECTION .s16]
[BITS	16]
LABEL_BEGIN:
	mov ax,cs
	mov ds,ax
	mov es,ax
	mov ss,ax
	mov sp,0100h

	; 得到内存数
	mov ebx,0
	mov di,ARDStruct
.loop1:
	mov eax,0E820h
	mov ecx,20
	mov edx,0534D4150h
	int 15h
	jc LABEL_MEM_CHK_FAIL
	inc word [dwMemSize]
	call DispARDS
	cmp ebx,0
	jne .loop1
	mov ah,09h
	mov dx,szMCRMessage
	int 21h
	jmp LABEL_END
LABEL_MEM_CHK_FAIL:
	mov ah,09h
	mov dx,szMCFMessage
	int 21h
LABEL_END:
	mov ax,04c00h
	int 21h

DispARDS:
	push di
	push ebx
	push eax
	push ecx
	mov ecx,5
.loop2:
	mov eax,[es:di]
	call DispInt
	add di,4
	loop .loop2
	call DispEnter
	pop ecx
	pop eax
	pop ebx
	pop di
	ret

DispBuf:
	times 256 db 0
DispInt:
	push di
	push eax
	mov di,DispBuf
	shr eax,24
	call Hex2ASCII
	xchg ah,al
	cld
	stosw
	pop eax
	push eax
	shr eax,16
	call Hex2ASCII
	xchg ah,al
	stosw
	pop eax
	push eax
	shr eax,8
	call Hex2ASCII
	xchg ah,al
	stosw
	pop eax
	push eax
	call Hex2ASCII
	xchg ah,al
	stosw
	mov al,'h'
	stosb
	mov al,' '
	stosb
	mov al,'$'
	stosb
	push edx
	mov ah,09
	mov dx,DispBuf
	int 21h
	pop edx
	pop eax
	pop di
	ret

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
	pop edx
	ret

szEnter: db 0Ah,0Dh,'$'
DispEnter:
	push eax
	push edx
	mov ah,09
	mov dx,szEnter
	int 21h
	pop edx
	pop eax
	ret

