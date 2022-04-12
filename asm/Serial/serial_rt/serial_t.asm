.286
.MODEL small,stdcall
.stack 200h
serial_init proto
serial_out proto
serial_in proto
print_string proto
print_char proto
.data
msg1 db "transmit enquiry",0dh,0ah,'$'
msg2 db "receive acknowledgment",'$'
msg3 db "transmit acknowledgment",0dh,0ah,'$'
msg4 db "receive negative acknowledgment",0dh,0ah,'$'
msg5 db "established",0dh,0ah,'$'
msg6 db "host not mach",0dh,0ah,'$'
buf db 64 dup (0)
cflf db 0dh,0ah,'$'
host_name db 4 dup (' '),'$'
client_name db "C013",'$'
EOT EQU 04h
ENQ EQU 05h
ACK EQU 06h
NAK EQU 15h
.code
.startup
    push ds
    pop es
    invoke serial_init
    mov al,ENQ
    invoke serial_out
    lea dx,msg1
    invoke print_string
@@:
    invoke serial_in
    cmp al,ACK
    jne @b
    lea di,host_name
    mov cx,4
@@:
    invoke serial_in
    cld
    stosb
    loop @b
    lea dx,msg2
    invoke print_string
    mov dl,'['
    invoke print_char
    lea dx,host_name
    invoke print_string
    mov dl,']'
    invoke print_char
    lea dx,cflf
    invoke print_string
    mov al,ACK
    invoke serial_out
    mov cx,4
    lea si,client_name
@@:
    cld
    lodsb
    invoke serial_out
    loop @b
    lea dx,msg3
    invoke print_string
@@:
    invoke serial_in
    cmp al,ACK
    je establish
    cmp al,NAK
    je negative
    jmp @b
establish:
    lea di,buf
    mov cx,4
@@:
    invoke serial_in
    cld
    stosb
    loop @b
    lea si,host_name
    lea di,buf
    mov cx,4
    cld
    repe cmpsb
    jne not_mach
    lea dx,msg5
    invoke print_string
    jmp _exit
not_mach:
    lea dx,msg6
    invoke print_string
    jmp _exit
negative:
    lea dx,msg4
    invoke print_string
_exit:
.exit

serial_init proc near
    push dx
    mov ah,00h
    mov dx,0
    mov al,11100011b
    int 14h
    pop dx
    ret
serial_init endp

serial_out proc near
    push dx
    mov ah,01h
    mov dx,0
    int 14h
    pop dx
    ret
serial_out endp

serial_in proc near
    push dx
@@:
    mov ah,02h
    mov dx,0
    int 14h
    test ah,10000000b
    jne @b
    pop dx
    ret
serial_in endp

print_string proc near
    push ax
    mov ah,09h
    int 21h
    pop ax
    ret
print_string endp

print_char proc near
    mov ah,02h
    int 21h
    ret
print_char endp
end
