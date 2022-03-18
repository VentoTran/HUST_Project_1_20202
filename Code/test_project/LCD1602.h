#ifndef _LCD_1602_H_
#define _LCD_1602_H_

#include "delay.h"



void sendLowNibble(unsigned char DATA);

void sendHighNibble(unsigned char DATA);

void sendCmd(unsigned char CMD);

void sendData(unsigned char DATA);

void LCD_Init(void);

void LCD_Clr(void);

void setCursor(unsigned short x, unsigned short y);

void printChar(char c);

void printStrg(char* c);



#endif