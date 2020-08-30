#include <8052.h>
//#include <intrins.h>

typedef unsigned char u8;
typedef unsigned int u16;

#define led1 P0_0
#define led2 P0_1
#define led3 P0_2
#define led4 P0_3
#define led5 P0_4
#define led6 P0_5
#define led7 P0_6
#define led8 P0_7
#define led P0

#define key1 P1_0
#define key2 P1_1
#define key3 P1_2
#define key4 P1_3
#define key5 P1_4
#define key6 P1_5
#define key7 P1_6
#define key8 P1_7
#define keyscan P1

void delay(u16);
void keypros(void);

void main()
{
	led=0x00;
	delay(50000);
	led=0xFF;
	delay(50000);
	led=0x55;
	delay(50000);
	led=0xAA;
	delay(50000);
	led=0x55;
	delay(50000);
	led=0xAA;
	delay(50000);
	led=0x00;
	delay(50000);
	while(1)
	{
		keypros();
	}
}

void delay(u16 i)
{
	while(i)
	i--;
}

void keypros(void)
{
	if(key1 == 0)
	{
		delay(1000);
		if(key1 == 0);
			while(!key1);
		delay(1000);
		if(!key1);
			led1 = !led1;
	}

	if(key2 == 0)
	{
		delay(1000);
		if(key2 == 0);
			while(!key2);
		delay(1000);
		if(!key2);
			led2 = !led2;
	}

	if(key3 == 0)
	{
		delay(1000);
		if(key3 == 0);
			while(!key3);
		delay(1000);
		if(!key3);
			led3 = !led3;
	}

	if(key4 == 0)
	{
		delay(1000);
		if(key4 == 0);
			while(!key4);
		delay(1000);
		if(!key4);
			led4 = !led4;

	}

	if(key5 == 0)
	{
		delay(1000);
		if(key5 == 0);
			while(!key5);
		delay(1000);
		if(!key5);
			led5 = !led5;
	}

	if(key6 == 0)
	{
		delay(1000);
		if(key6 == 0);
			while(!key6);
		delay(1000);
		if(!key6);
			led6 = !led6;
	}

	if(key7 == 0)
	{
		delay(1000);
		if(key7 == 0);
			while(!key7);
		delay(1000);
		if(!key7);
			led7 = !led7;
	}

	if(key8 == 0)
	{
		delay(1000);
		if(key8 == 0);
			while(!key8);
		delay(1000);
		if(!key8);
			led8 = !led8;
	}
}
