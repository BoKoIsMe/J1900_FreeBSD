#include <stdio.h>

int main(void)
{
	char buffer[255];
	char *bufptr;
	bufptr = buffer;
	int num = buffer + sizeof(buffer) - bufptr -1;
	printf("&buffer = 0x%x\n",buffer);
	printf("*bufptr = 0x%x\n",bufptr);
	printf("sizeof(buffer) =  %d\n",sizeof(buffer));
	printf("buffer + sizeof(buffer) - bufptr -1 =%d\n",num);
	return(0);
}

