// ec.c -- 错误调用
#include <stdio.h>

int main(void)
{
	float a = 3.0f;
	double b = 3.0f;
	long c = 123123123;
	long d = 456456456;
	printf("%ld %ld %ld %ld\n",a,b,c,d);
	return 0;
}
