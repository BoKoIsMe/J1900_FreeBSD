#include <stdio.h>

/*

最大公约数
Greatest Common Divisor
求解

*/

#define iGCD iGreatestCommonDivisor
#define iHCD iGreatestCommonDivisor
#define TRUE 1
#define FALSE 0

int iGreatestCommonDivisor(int a,int b);

int main(void)
{
	int a,b;
	printf("输入两个整形变量求公约数\na =");
	scanf("%d",&a);
	printf("b =");
	scanf("%d",&b);
	printf("\n最大公约数是:%d\n",iGCD(a,b));
	return 0;
}

int iGreatestCommonDivisor(int a,int b)
{
	int result = 1;
	if (!a)
		return 0;
	else if (!b)
		return 0;
	else if (a == b)
		return a;
	else if (a > b)
	{
		if (!(a % b))
			return b;
		result = b / 2;
	}
	else
	{
		if (!(b % a))
			return a;
		result = b /2;
	}
	while((a % result) | (b % result))
		result--;
	return result;
}

