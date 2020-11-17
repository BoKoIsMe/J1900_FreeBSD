;随机数生成范例
;幻数设置
FREAD					EQU 0x00000001
FWRITE					EQU 0x00000002
FILE_OPEN_FAILURE		EQU -1
AUE_EXIT				EQU 1
AUE_WRITE				EQU 4
AUE_OPEN_RWTC			EQU 5 ;STD { int open(char *path, int flags, int mode); })
AUE_CLOSE				EQU 6 ;STD { int close(int fd); })
STDOUT					EQU 1
CPUID_STATUS_SUCCESS	EQU 0
CPUID_STATUS_FAILURE	EQU 1 

section .data
;数据段
	ttyname db "./1.txt",0
	tty_fd	dq 0
	msg		db "0x00000000",10,0		;字串
	hbyte0	equ $ - msg
	msg1	db "Start run CPUID & rdrand",10,0	;字串2
	hbyte1	equ $ - msg1

section .text
;代码段
global _start
_start:
	push hbyte1
	push msg1
	push STDOUT
	mov eax,AUE_WRITE
	call kernel

	mov eax,1
	cpuid
	bt ecx,30;位测试失败则CPU不支持真随机数
	mov ebx,CPUID_STATUS_FAILURE;检测失败退出代码
	jnc .exit

;如果无随机数可用,rdrand执行后返回置标志位 CF = 0
;根据Intel文档建议 测试10次以上
	mov ecx,11
.loop1:
	dec ecx
	jecxz .exit;退出码已赋值给rdi
	rdrand eax
	jnc .loop1

; HEX2ASCII
	;mov rdi,msg+9
	;mov ecx,8
;.loop2:
	;mov edx,eax
	;and edx,0FH
	;mov r8d,7
	;xor r9d,r9d;清零
	;cmp dl,9
	;cmova r9,r8
	;add edx,r9d
	;add [rdi],dl
	;shr eax,4
	;dec edi
	;loop .loop2

	push hbyte0
	push msg
	push STDOUT
	mov eax,AUE_WRITE
	call kernel

	mov ebx,CPUID_STATUS_SUCCESS;正常退出码
.exit:
	mov eax,AUE_EXIT
	push ebx
	call kernel

kernel:
	int 80h
	ret

