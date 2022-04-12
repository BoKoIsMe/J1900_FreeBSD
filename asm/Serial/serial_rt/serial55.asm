.286
.MODEL small,stdcall
;IOY0 EQU 0DC00h
IOY0 EQU 2F8h
MY16550_0 EQU IOY0 + 00h *4
MY16550_1 EQU IOY0 + 01h *4
MY16550_3 EQU IOY0 + 03h *4

dally proto

.stack 200h

.code
.startup
    mov dx,MY16550_3
    mov al,80h
    out dx,al

    mov dx,MY16550_0
    mov al,0ch
    out dx,al

    mov dx,MY16550_1
    mov al,00h
    out dx,al

    mov dx,MY16550_3
    mov al,1bh
    out dx,al

    mov dx,MY16550_1
    mov al,00h
    out dx,al

send:
    mov dx,MY16550_0
    mov al,53h
    out dx,al
    call dally

    mov ah,1
    int 16h
    jz send

    mov dx,MY16550_0
    mov al,5ah
    out dx,al

.exit

dally proc near
    push cx
    push ax
    mov cx,0100h
D1:
    mov ax,1000h
D2:
    dec ax
    jnz D2
    loop D1
    pop ax
    pop cx
    ret
dally endp

end
