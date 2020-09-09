#include <stdio.h>
#define MYSTR "greastyeer"

int str_len(char str[]);

int main(void)
{
	char str[sizeof MYSTR + 1] = MYSTR;
	str[sizeof MYSTR] = 0;
	int result = str_len(&str[0]);
	printf("string count result = %d\n",result);
	return 0;
}

int str_len(char str[])
{
	int number = 0;
	for(int index = 0;str[index] != '\0';index++)
		number += 1;
	return number;
}

