#ifndef _PORT_H_
#define _PORT_H_

#include "reg52.h"
#define FREQ_OSC 11059200ul


sfr LCD = 0x80;
sbit RS = P0^0;
sbit RW = P0^1;
sbit EN = P0^2;

sbit LED = P2^0;

sfr ADC0804_Data = 0x90;
sbit ADC0804_CS = P3^2;
sbit ADC0804_RD = P3^3;
sbit ADC0804_WR = P3^4;
sbit ADC0804_INTR = P3^6;

sbit RX = P3^0;
sbit TX = P3^1;

sbit CNT = P3^5;


#endif