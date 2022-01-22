#include <stdio.h>
#define ALPHA 'A'
#define OMEGA 'Z'
#define alpha 'a'
#define omega 'z'
#define zero '0'
#define nine '9'
#define SPACE ' '
#define SLASH '/'
#define COLON ':'
#define AT '@'
#define OPENINGBRACKET '['
#define GRAVEACCENT '`'
#define OPENINGBRACE '{'
#define TILDE '~'
#define MAXBUF 255
int howManyAlphabetCharacterInString(const char string[],const int limit);
int howManyDigitalCharacterInString(const char string[],const int limit);
int howManySignCharacterInString(const char string[],const int limit);
int main(void)
{
	char ch = 0;
	char buf[MAXBUF + 1];
	int index = 0,n,alphabet,digital,sign;
	printf("Input n:");
	scanf("%d",&n);
	getchar();
	while((ch = getchar()) != EOF)
	{
		if ((index == MAXBUF) || (index == n) || ch == '\n')
		{
			buf[index] = EOF;
			buf[index + 1] = 0;
			break;
		}
		buf[index] = ch;
		index++;
	}
	printf("roman alphabet charcter = %d,digital character = %d,sign charcter = %d\n",\
		howManyAlphabetCharacterInString(buf,index < MAXBUF?index + 1:MAXBUF),\
		howManyDigitalCharacterInString(buf,index < MAXBUF?index + 1:MAXBUF),\
		howManySignCharacterInString(buf,index < MAXBUF?index + 1:MAXBUF));
	return 0;
}
int howManyAlphabetCharacterInString(const char string[],const int limit)
{
	int index = 0,count = 0;
	while(index < limit)
	{
		if((string[index] >= ALPHA && string[index] <= OMEGA) \
			|| (string[index] >= alpha && string[index] <= omega))
			count++;
		index++;
	}
	return count;
}
int howManyDigitalCharacterInString(const char string[],const int limit)
{
	int index = 0,count = 0;
	while(index < limit)
	{
		if(string[index] >= zero && string[index] <= nine)
			count++;
		index++;
	}
	return count;
}
int howManySignCharacterInString(const char string[],const int limit)
{
	int index = 0,count = 0;
	while(index < limit)
	{
		if((string[index] >= SPACE && string[index] <= SLASH) \
			|| (string[index] >= COLON && string[index] <= AT) \
			|| (string[index] >= OPENINGBRACKET && string[index] <= GRAVEACCENT) \
			|| (string[index] >= OPENINGBRACE && string[index] <= TILDE))
			count++;
		index++;
	}
	return count;
}
