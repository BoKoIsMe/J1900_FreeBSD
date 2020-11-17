.model small,stdcall

;const var define
TRUE                    EQU -1
FALSE                   EQU 0
;==========================================
;Baudrate set word(divisor)
BAUDRATE9600            EQU 12
BAUDRATE4800            EQU 24
BAUDRATE2400            EQU 48
BAUDRATE1200            EQU 96
BAUDRATE600             EQU 192
BAUDRATE300             EQU 384
BAUDRATE150             EQU 768
BAUDRATE110             EQU 1040
;if DLAB = 1,divisor latch low byte
;After OUT portbase + 3,80H this port holds
;the low byte of the clock divisor
;which, together with the high byte
;(port base + 1) constitute 16-bit value
;that sets the baud rate as context

;==========================================
;IER(interrupt enable register),prot base + 1 Write
;name                   BIT 76543210
ENABLE_RxD_INT          EQU 00000001B ;interrupt when rec'd data is available
ENABLE_TxD_INT          EQU 00000010B ;interrupt when transmit buffer is empty
ENABLE_RLS_INT          EQU 00000100B ;enable int on rec'r line status (err or break)
ENABLE_MODEM_STATUS     EQU 00001000B ;enable int on modem status (CTS,DSR,RI,RLSD)
IER                                                     EQU 1

;==========================================
;FIFO control register (write only) port base + 2
;name                   BIT 76543210
ENABLE_FIFO             EQU 00000001B ;enable FIFO mode
CLEAR_RCV_FIFO          EQU 00000010B ;clear receiver FIFO
CLEAR_TRS_FIFO          EQU 00000100B ;clear transmit FIFO
DMA_MODE_SELECT         EQU 00001000B ;DMA mode select
;FIFO interrupt trigger level:
FIFO1BYTE               EQU 00000000B ;1 byte FIFO buf
FIFO4BYTE               EQU 01000000B ;4 byte FIFO buf
FIFO8BYTE               EQU 10000000B ;8 byte FIFO buf
FIFO16BYTE              EQU 11000000B ;16 byte FIFO buf
FIFO_STATUS             EQU 2
;IIR(interrupt identification register) port base +2 (read)
;When an interrupt occurs,read this register to find what caused it.
;test by bit
IIR                     EQU 2
;name                   BIT 76543210
NO_INT_PENDING          EQU 00000001B ;no interrupt pending; can be used in polling
INT_STATUS_MASK         EQU 00000110B ; masked with test bit
RLS_INT                 EQU 00000000B ; receiver line status interrupt.
;Occurs on:overrun, parity, or framing error, or break
;Reset by reading line status (port base + 5)
RxD_AVAILABLE           EQU 00000010B ;received data available
;Reset by reading receiver buffer (port base + 0)
TxD_EMPTY               EQU 00000100B ;transmitter buffer empty
;Reset by writing transmitter buffer (port base + 0)
MODEM_STATUS            EQU 00000110B ;modem status. Occurs upon:
;Clear To Send, Data Set Ready, Ring Ind, or
;Rec'd Line Signal Detect.
;Reset by reading modem status (port base + 6).
FIFO_TIMEOUT            EQU 00001000B ;Receiver FIFO time-out
FIFO_STATUS_MASK        EQU 11000000B ; masked with test bit
FIFO_DISABLED           EQU 00000000B ;FIFOs disabled (or old 8250)
FIFO_ENABLED            EQU 11000000B ;FIFOs enabled
FIFO_DMA_MODE_ENABLED   EQU 01000000B ;FIFOs enbled and DMA mode

;==========================================
;LCR(line control register) bit set,port base + 3 Read/Write
;name                   BIT 76543210
BIT5                    EQU 00000000B ;word length:5 bits
BIT6                    EQU 00000001B ;word length:6 bits
BIT7                    EQU 00000010B ;word length:7 bits
BIT8                    EQU 00000011B ;word length:8 bits
; word length: 00B = 5 bits, 01B = 6 bits, 10B = 7 bits, 11B = 8 bits
STOPBIT_1BIT            EQU 00000000B ;stop bit:1 bit
STOPBIT_2BIT            EQU 00000100B ;stop bits:2 bits (some oddball exceptions)
NONE_PARITY             EQU 00000000B ;none parity
ODD_PARITY              EQU 00001000B ;odd parity
EVEN_PARITY             EQU 00011000B ;even parity
ENABLE_STUCK_PARITY     EQU 00100000B ;not used by BIOS
DISABLE_STUCK_PARITY    EQU 00000000B ;not used by BIOS
ENABLE_BREAK_CONTROL    EQU 01000000B ;enable break control. 1=start sending 0s(spcs)
DISABLE_BREAK_CONTROL   EQU 00000000B ;disable break control.
DLAB                    EQU 10000000B ;Divisor Lacth Access Bit
LCR                                                     EQU 3

;==========================================
;MCR(modem control register) port base + 4 Write
;name                   BIT 76543210
DTR_ACT                 EQU 00000001B ;activate -DTR (-data trmnl rdy), 0=deactivate
RTS_ACT                 EQU 00000010B ;activate -RTS (-request to send), 0=deactivate
OUT1_ACT                EQU 00000100B ;activate -OUT1 (spare,user-designated output)
OUT2_ACT                EQU 00001000B ;activate -OUT2
MODEM_DIAGNOSTIC        EQU 00010000B ;activate loopback for diagnostic testing
MCR                                                     EQU 4

;==========================================
;LSR(line status register) port base + 5 read
;Note: bits 1-4 cause interrupt if enabled (port base + 1)
;name                   BIT 76543210
DATA_READ               EQU 00000001B ;data ready (DR). Reset by reading recv'r buffer
OVERRUN_ERROR           EQU 00000010B ;overrun error (OE). Previous character is lost
PARITY_ERROR            EQU 00000100B ;parity error (PE). Reset by reading line status
FRAMING_ERROR           EQU 00001000B ;framing error (FE). Bad stop bit in character
BREAK_INDICATED         EQU 00010000B ;break indicated (BI). Sustained space received
THR_EMPTY               EQU 00100000B ;transmitter holding register empty. OK to send
TRANSMITTER_EMPTY       EQU 01000000B ;transmitter empty. No data being processed.
FIFO_RCV_ERROR          EQU 10000000B ;(16450 UARTs) 1=Receiver FIFO error
LSR                                                     EQU 5

;==========================================
;MSR(modem status register) port base + 6 read
;name                   BIT 76543210
DCTS_CHANGED            EQU 00000001B ;Delta Clear To Send (DCTS) has changed state
DDSR_CHANGED            EQU 00000010B ;Delta Data Set Ready (DDSR) has changed state
TERI_ACT                EQU 00000100B ;Trailing Edge Ring Indicator (TERI) is active
DDCD_CHANGED            EQU 00001000B ;Delta Data Carrier Detect (DDCE) has changed
CTS_ACT                 EQU 00010000B ;Clear To Send (CTS) is active
DSR_ACT                 EQU 00100000B ;Data Set Ready (DSR) is active
RI_ACT                  EQU 01000000B ;Ring Indicator (RI) is active
DCD_ACT                 EQU 10000000B ;Data Carrier Detect (DCD) is active
MSR                                                     EQU 6

;==========================================
;read/write scratch pad port base + 7

SERIAL_PORT_SEGMENT             EQU 0040h
SERIAL_COM1_PORT                        EQU 0000h
SERIAL_COM2_PORT                        EQU 0002h

get_serial_port proto
init_serial proto
set_baudrate proto
set_serial_mode proto
receive proto
sending proto

.stack 200h

.data
msg_timeout db "sending time-out.",0dh,0ah,'$'

.data?
crrPort WORD ?

.code
main proc
.startup
	push ds
	pop es
	invoke init_serial
	mov WORD ptr crrPort,ax
	;mov dx,crrPort
	;add dx,FIFO_STATUS
	;mov al,ENABLE_FIFO or CLEAR_RCV_FIFO or CLEAR_TRS_FIFO or FIFO1BYTE
	;out dx,al
	mov dx,crrPort
	xor ax,ax
	add dx,IER
	out dx,al
	mov cx,300
	@@:
	push cx
	mov dx,crrPort
	mov bl,'A'
	invoke sending
	cmp ah,FALSE
	je send_timeout
	mov bl,'C'
	invoke sending
	cmp ah,FALSE
	je send_timeout
	mov bl,'K'
	invoke sending
	cmp ah,FALSE
	je send_timeout
	pop cx
	loop @b
	jmp _exit
send_timeout:
	mov dx,offset msg_timeout
	mov ah,09h
	int 21h
	pop cx
	loop @b
_exit:
.exit
main endp

init_serial proc near
	local wSerialPort:WORD
	mov dx,SERIAL_COM1_PORT
	invoke get_serial_port
	mov WORD ptr wSerialPort,ax
	mov bx,BAUDRATE9600
	mov dx,wSerialPort
	invoke set_baudrate
	mov dx,wSerialPort
	invoke set_serial_mode
	mov ax,wSerialPort
	ret
init_serial endp

receive proc near
	local port:WORD
	mov WORD ptr port,dx
	add dx,IIR
	mov cx,50000
@@:
	in al,dx
	test al,RxD_AVAILABLE
	jne @f
	loop @b
	mov ah,FALSE
	jmp receive_return
@@:
	mov dx, port
	in al,dx
	mov ah,TRUE
	;stosb
	;add dx,IIR
	;jmp @b
receive_return:
	ret
receive endp

sending proc near
	local port:WORD
	mov WORD ptr port,dx
	add dx,IIR
	mov cx,50000
@@:
	in al,dx
	test al,TxD_EMPTY
	jne @f
	loop @b
	mov ah,FALSE
	jmp send_return
@@:
	mov bl,al
	mov dx, port
	out dx,al
	mov ah,TRUE
	;stosb
	;add dx,IIR
	;jmp @b
send_return:
	ret
sending endp


get_serial_port proc near
; get serial com port,DX = COM?
	push ds
	push si
	mov ax,SERIAL_PORT_SEGMENT
	mov ds,ax
	mov si,dx
	lodsw
	pop si
	pop ds
	ret
get_serial_port endp

set_baudrate proc near
	push dx
	add dx,LCR
	in al,dx
	or al,DLAB
	out dx,al
	xchg ax,bx
	pop dx
	;push dx
	out dx,al
	inc dx
	mov al,ah
	out dx,al
	;mov al,DLAB
	;not al
	;and al,bl
	;pop dx
	;add dx,LCR
	;out dx,al
	ret
set_baudrate endp

set_serial_mode proc near
	mov al,DISABLE_STUCK_PARITY or NONE_PARITY or STOPBIT_1BIT or BIT8
	out dx,al
	ret
set_serial_mode endp


end
