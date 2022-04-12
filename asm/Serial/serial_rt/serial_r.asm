.286
.MODEL small,stdcall
.stack 200h
.data
error_1 db "recv error 1",0dh,0ah,"$"
.code
.startup
    push ds
    pop es
    mov ah,00h
    mov dx,0
    mov al,11100011b
    int 14h
read_next:
    mov ah,02h
    mov dx,0
    int 14h
    test ah,10000000b
    jne read_next
    cmp al,04h
    je end_recv
    mov ah,02h
    mov dl,al
    int 21h
    jmp read_next
end_recv:
.exit
end
