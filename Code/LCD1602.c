#include "LCD1602.h"
#include "port.h"


void sendLowNibble(unsigned char DATA)
{
	LCD = (LCD & 0x0F);
	LCD |= (DATA  << 4);
}


void sendHighNibble(unsigned char DATA)
{
	LCD = (LCD & 0x0F);
	LCD |= (DATA & 0xF0);
}


void sendCmd(unsigned char CMD)
{
	RW = 0;		//write to LCD
	RS = 0; 	//send CMD
	
	sendHighNibble(CMD);
	
	EN = 0;
	delay(1);
	EN = 1;
	delay(2);
	
	sendLowNibble(CMD);
	
	EN = 0;
	delay(1);
	EN = 1;
	delay(2);
}


void sendData(unsigned char DATA)
{
	RW = 0;		//write to LCD
	RS = 1; 	//send DATA
	
	sendHighNibble(DATA);
	
	EN = 0;
	delay(1);
	EN = 1;
	delay(2);
	
	sendLowNibble(DATA);
	
	EN = 0;
	delay(1);
	EN = 1;
	delay(2);
}


void LCD_Init(void)
{
	delay(50);  		/* LCD Power ON Initialization time >15ms */
	sendCmd (0x02); /* 4bit mode */
	delay(10);
	sendCmd (0x28); /* Initialization of 16X2 LCD in 4bit mode */
	delay(10);
	sendCmd (0x0C); /* Display ON Cursor OFF */
	delay(10);
	sendCmd (0x06); /* Auto Increment cursor */
	delay(10);
	sendCmd (0x01); /* Clear display */
	delay(10);
	sendCmd (0x80); /* Cursor at home position */
	delay(10);
}


void LCD_Clr(void)
{
	sendCmd (0x01);
}

void setCursor(unsigned short x, unsigned short y)
{
	if (y == 0)
		sendCmd ((x & 0x0F) | 0x80);
	else if (y == 1)
		sendCmd ((x & 0x0F) | 0xC0);
}


void printChar(char c)
{
	sendData(c);
}


void printStrg(char* c)
{
	while(*c)
	{
		printChar(*c++);
	}
}


