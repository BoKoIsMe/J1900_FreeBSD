.386
.model flat, stdcall
option casemap :none

include windows.inc
include user32.inc
include kernel32.inc
include masm32.inc
include gdi32.inc

includelib gdi32.lib
includelib user32.lib
includelib kernel32.lib
includelib masm32.lib
include macro.asm

setConsoleColor proto color:DWORD
	
.data
	lpFMTHEX 	db "0x%08X",0
	lpFMTDEC 	db "%d",0
	lpcrlf 		db 0dh,0ah,0
	lpConsoleTitle db "�鿴����̨����",0
	lpX 			db " x = ",0
	lpY 			db " y = ",0
	lpCol 		db " Col = ",0
	lpRaw 		db " Raw = ",0
	lpTop 		db " Top = ",0
	lpBottom 	db " Bootom = ",0
	lpLeft 		db " Left = ",0
	lpRight 		db " Right = ",0
	lpMsg1		db "��ǰ����̨���:",0
	lpMsg2 		db "����̨��������С:",0
	lpMsg3 		db "���λ��(�ǵ�ǰ):",0
	lpMsg4 		db "�����С(��λ:ASCII�ַ�):",0
	lpMsg5 		db "������С:",0
	lpMsg6 		db "��ǰ�ַ���ɫ����:",0
	
    enmCFC_Red          = FOREGROUND_INTENSITY or FOREGROUND_RED
    enmCFC_Green        = FOREGROUND_INTENSITY or FOREGROUND_GREEN
    enmCFC_Blue         = FOREGROUND_INTENSITY or FOREGROUND_BLUE
    enmCFC_Yellow       = FOREGROUND_INTENSITY or FOREGROUND_RED or FOREGROUND_GREEN
    enmCFC_Purple       = FOREGROUND_INTENSITY or FOREGROUND_RED or FOREGROUND_BLUE
    enmCFC_Cyan         = FOREGROUND_INTENSITY or FOREGROUND_GREEN or FOREGROUND_BLUE
    enmCFC_Gray         = FOREGROUND_INTENSITY
    enmCFC_White        = FOREGROUND_RED or FOREGROUND_GREEN or FOREGROUND_BLUE
    enmCFC_HighWhite    = FOREGROUND_INTENSITY or FOREGROUND_RED or FOREGROUND_GREEN or FOREGROUND_BLUE
    enmCFC_Black        = 0
	
    enmCBC_Red          = BACKGROUND_INTENSITY or BACKGROUND_RED
    enmCBC_Green        = BACKGROUND_INTENSITY or BACKGROUND_GREEN
    enmCBC_Blue         = BACKGROUND_INTENSITY or BACKGROUND_BLUE
    enmCBC_Yellow       = BACKGROUND_INTENSITY or BACKGROUND_RED or BACKGROUND_GREEN
    enmCBC_Purple       = BACKGROUND_INTENSITY or BACKGROUND_RED or BACKGROUND_BLUE
    enmCBC_Cyan         = BACKGROUND_INTENSITY or BACKGROUND_GREEN or BACKGROUND_BLUE
    enmCBC_White        = BACKGROUND_RED or BACKGROUND_GREEN or BACKGROUND_BLUE
    enmCBC_HighWhite    = BACKGROUND_INTENSITY or BACKGROUND_RED or BACKGROUND_GREEN or BACKGROUND_BLUE
    enmCBC_Black        = 0
	
	;   0 = ��ɫ      8 = ��ɫ
	;   1 = ��ɫ      9 = ����ɫ
	;   2 = ��ɫ      A = ����ɫ
	;   3 = ǳ��ɫ    B = ��ǳ��ɫ
	;   4 = ��ɫ      C = ����ɫ
	;   5 = ��ɫ      D = ����ɫ
	;   6 = ��ɫ      E = ����ɫ
	;   7 = ��ɫ      F = ����ɫ
	
.data?
	hOutputConsole DWORD ?
	crtConsoleAtt CONSOLE_SCREEN_BUFFER_INFO <>
	buffer	db MAX_PATH dup(?)
	;sperc 	db MAX_PATH dup(?)
.CODE
START:
	call fillBufZero
	invoke GetStdHandle,STD_OUTPUT_HANDLE
	mov hOutputConsole,eax
	invoke GetConsoleScreenBufferInfo,hOutputConsole,offset crtConsoleAtt
	invoke SetConsoleTitle,offset lpConsoleTitle
	invoke SetConsoleTextAttribute,hOutputConsole,enmCFC_Green
	invoke wsprintf,offset buffer,offset lpFMTHEX,hOutputConsole
	;invoke locate,0,0			;�趨����ı�������
	invoke StdOut,offset lpMsg1
	invoke SetConsoleTextAttribute,hOutputConsole,enmCFC_Yellow
	invoke StdOut,offset buffer
	call fillBufZero
	invoke StdOut,offset lpcrlf
	invoke setConsoleColor,enmCFC_Green
	invoke StdOut,offset lpMsg2
	invoke StdOut,offset lpX
	invoke wsprintf,offset buffer,offset lpFMTDEC,crtConsoleAtt.dwSize.x
	invoke setConsoleColor,enmCFC_Yellow
	invoke StdOut,offset buffer
	call fillBufZero
	invoke setConsoleColor,enmCFC_Green
	invoke StdOut,offset lpY
	invoke wsprintf,offset buffer,offset lpFMTDEC,crtConsoleAtt.dwSize.y
	invoke setConsoleColor,enmCFC_Yellow
	invoke StdOut,offset buffer
	call fillBufZero
	invoke setConsoleColor,enmCFC_Green
	invoke StdOut,offset lpcrlf
	
	invoke StdOut,offset lpMsg3
	invoke StdOut,offset lpCol
	invoke wsprintf,offset buffer,offset lpFMTDEC,crtConsoleAtt.dwCursorPosition.x
	invoke setConsoleColor,enmCFC_Yellow
	invoke StdOut,offset buffer
	call fillBufZero
	invoke setConsoleColor,enmCFC_Green
	invoke StdOut,offset lpRaw
	invoke wsprintf,offset buffer,offset lpFMTDEC,crtConsoleAtt.dwCursorPosition.y
	invoke setConsoleColor,enmCFC_Yellow
	invoke StdOut,offset buffer
	call fillBufZero
	invoke StdOut,offset lpcrlf
	
	invoke setConsoleColor,enmCFC_Green
	invoke StdOut,offset lpMsg4
	invoke StdOut,offset lpTop
	invoke wsprintf,offset buffer,offset lpFMTDEC,crtConsoleAtt.srWindow.Top
	invoke setConsoleColor,enmCFC_Yellow
	invoke StdOut,offset buffer
	call fillBufZero
	invoke setConsoleColor,enmCFC_Green
	invoke StdOut,offset lpBottom
	invoke wsprintf,offset buffer,offset lpFMTDEC,crtConsoleAtt.srWindow.Bottom
	invoke setConsoleColor,enmCFC_Yellow
	invoke StdOut,offset buffer
	call fillBufZero
	invoke setConsoleColor,enmCFC_Green
	invoke StdOut,offset lpLeft
	invoke wsprintf,offset buffer,offset lpFMTDEC,crtConsoleAtt.srWindow.Left
	invoke setConsoleColor,enmCFC_Yellow
	invoke StdOut,offset buffer
	call fillBufZero
	invoke setConsoleColor,enmCFC_Green
	invoke StdOut,offset lpRight
	invoke wsprintf,offset buffer,offset lpFMTDEC,crtConsoleAtt.srWindow.Right
	invoke setConsoleColor,enmCFC_Yellow
	invoke StdOut,offset buffer
	call fillBufZero
	invoke StdOut,offset lpcrlf
	
	invoke setConsoleColor,enmCFC_Green
	invoke StdOut,offset lpMsg5
	invoke setConsoleColor,enmCFC_Green
	invoke StdOut,offset lpCol
	invoke wsprintf,offset buffer,offset lpFMTDEC,crtConsoleAtt.dwMaximumWindowSize.x
	invoke setConsoleColor,enmCFC_Yellow
	invoke StdOut,offset buffer
	call fillBufZero
	invoke setConsoleColor,enmCFC_Green
	invoke StdOut,offset lpRaw
	invoke wsprintf,offset buffer,offset lpFMTDEC,crtConsoleAtt.dwMaximumWindowSize.y
	invoke setConsoleColor,enmCFC_Yellow
	invoke StdOut,offset buffer
	call fillBufZero
	invoke StdOut,offset lpcrlf
	
	invoke setConsoleColor,enmCFC_Green
	invoke StdOut,offset lpMsg6
	invoke wsprintf,offset buffer,offset lpFMTHEX,crtConsoleAtt.wAttributes
	invoke setConsoleColor,enmCFC_Yellow
	invoke StdOut,offset buffer
	call fillBufZero
	invoke StdOut,offset lpcrlf
	
	invoke setConsoleColor,crtConsoleAtt.wAttributes
	;��ͣ��ʾ,�س����ر�
	;invoke StdIn,addr buffer,sizeof buffer
	invoke ExitProcess,0
	
fillBufZero proc
	pusha
	xor eax,eax
	mov edi,offset buffer
	mov ecx,MAX_PATH
	rep stosb
	popa
	ret
fillBufZero endp

setConsoleColor proc color:DWORD
	;invoke GetStdHandle,STD_OUTPUT_HANDLE
	;mov hOutputConsole,eax
	invoke SetConsoleTextAttribute,hOutputConsole,color
	ret
setConsoleColor endp

end START
