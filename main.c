/*
 * prj1.c
 *
 * Created: 2024-04-08 오후 2:22:36
 * Author : 김종원
 */ 
// THIS IS Number #1
//THIS IS Number #2

//THIS IS Number #4
//THIS IS Number #5

#define F_CPU  3333333UL
#include <avr/io.h>
#include <util/delay.h>
#define LATH	(PORTE.OUT|= PIN1_bm)
#define LATL	(PORTE.OUT &=~PIN1_bm)
#define CLKH	(PORTE.OUT|= PIN0_bm)
#define CLKL	(PORTE.OUT &=~PIN0_bm)
#define OEH		(PORTE.OUT|= PIN2_bm)
#define OEL		(PORTE.OUT &=~PIN2_bm)


void initPort(void)
{
	PORTA.DIR=0xff;
	PORTF.DIR=0xff;
	PORTE.DIR=0xff;
}

int main(void)
{
    /* Replace with your application code */
	uint8_t i,j;
	uint32_t color1=0xaabbccdd;
	uint32_t color2;
	initPort();
    while (1) 
    {
	
	OEL;
	for(j=0;j<9;j++)
	{
		color2=color1;
		PORTF.OUT=7;	
		LATL;
		for (i=0;i<32;i++)
			{
				CLKL;//     00BGRBGR
				PORTA.OUT=0b00001011;//x22;//(color2 >>1) & 0x7f;
				CLKH;
			}
			LATH;
	}
		_delay_ms(5);	
	OEH;
	_delay_ms(1);
    }
	//return 0;
}

