; 描述符
; usage: Descriptor Base, Limit ,Attr
;		 Base:	dd
;		 Limit: dd (low 20 bits available)
;		 Attr:	dw (lower 4 bits of higher byte are always 0)
%macro Descriptor 3
		dw %2 & 0FFFFh								; 段界限1
		dw %1 & 0FFFFh								; 段基址1
		db (%1 >> 16) & 0FFh						; 段基址2
		dw ((%2 >> 8) & 0F00h) | (%3 & 0F0FFh)		; 属性1 + 段界限2 + 属性2
		db (%1 >> 24) & 0FFh						; 段基址3
%endmacro ; 共 8 字节

; 描述符类型
DA_32		equ 4000h		; 32 位段
DA_DPL0		equ 00h			; DPL = 0
DA_DPL1		equ 20h			; DPL = 1
DA_DPL2		equ 40h			; DPL = 2
DA_DPL3		equ 60h			; DPL = 3

; 存储段描述符类型
DA_DR		equ 90h			; 存在的只读数据段类型值
DA_DRW		equ 92h			; 存在的可读写数据段属性值
DA_DRWA		equ 93h			; 存在的已访问可读写数据段类型值
DA_C		equ 98h			; 存在的只执行代码段属性值
DA_CR		equ 9Ah			; 存在的可执行可读代码段属性值
DA_CCO		equ 9Ch			; 存在的只执行一致性代码段属性值
DA_CCOR		equ 9Eh			; 存在的可执行可读一致性代码段属性值

; 系统段描述符类型
DA_LDT		equ 82h			; 局部描述符表段类型值
DA_TaskGate equ 85h			; 任务门类型值
DA_386TSS	equ 89h			; 可用 386 任务状态段类型值
DA_386CGate equ 8Ch			; 386 调用门类型值
DA_386IGate equ 8Eh			; 386 中断门类型值
DA_386TGate equ 8Fh			; 386 陷阱门类型值

