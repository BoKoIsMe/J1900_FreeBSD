DATA SEGMENT
A DB 05FH
HEX_ASCII_1 DB 1 dup (?)
HEX_ASCII_2 DB 1 dup (?)
_ED_CAHR DB 0DH,0AH,'$'
DATA ENDS
CODE SEGMENT
     ASSUME CS:CODE,DS:DATA
START:MOV AX,DATA;��DS�γ�ֵ
      MOV DS,AX
      MOV DL,A
      MOV CL,4
      SHR DL,CL;����4λ��ø�4λ
      ADD DL,030H;0��9��30H,A~F��37H
      CMP DL,'9';��˫��֧ת��Ϊ����֧
      JBE NEXT1
      ADD DL,7
NEXT1:MOV HEX_ASCII_1,DL
      MOV DL,A
      AND DL,0FH;��4λ��0��õ�4λ
      ADD DL,30H
      CMP DL,'9'
      JBE NEXT2
      ADD DL,7
NEXT2:MOV HEX_ASCII_2,DL
      MOV DX,OFFSET HEX_ASCII_1
      MOV AH,09
      INT 21H
      MOV AH,4CH
      INT 21H
CODE ENDS
     END START
