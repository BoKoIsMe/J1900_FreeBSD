#include <stdio.h>

void binout(long hex);

int main(int argc,char* argv[])
{
	binout(-1);
	binout(0);
	binout(0x5555555555555555);
	binout(0xaaaaaaaaaaaaaaaa);
	return 0;
}

void binout(long hex)
{
	char buf[100];
	__asm__("leaq %0,%%rdi"
	:
	:"p"(&buf[0])
	:"%rdi"
	); 
	__asm__("movq $64,%rcx" ); 
	__asm__("mov %0,%%rdx"
	:
	:"m"(hex)
	:"%rdx"
	); 
	__asm__("again:" ); 
	__asm__("rol $1,%rdx" ); 
	__asm__("jc one" ); 
	__asm__("movb $0x30,%al" );
	__asm__("cld" ); 
	__asm__("stosb" ); 
	__asm__("jmp next" ); 
	__asm__("one:" ); 
	__asm__("movb $0x31,%al" ); 
	__asm__("cld" ); 
	__asm__("stosb" ); 
	__asm__("next:" ); 
	__asm__("loop again" ); 
	__asm__("movb $0,%al" ); 
	__asm__("cld" ); 
	__asm__("stosb" ); 
	printf ("%s\n",buf);
}
