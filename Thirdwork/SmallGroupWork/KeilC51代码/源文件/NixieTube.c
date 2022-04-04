#include<reg52.h>
typedef unsigned char u8;
typedef unsigned int u16;

u8 code shuma[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void delay(u16 i)
{
	while(i--);
}

void main()
{
	while(1)
	{
		u16 j;
		for(j=0;j<10;j++)
		{
			P0=shuma[j];
			delay(50000);
		}
	}
}