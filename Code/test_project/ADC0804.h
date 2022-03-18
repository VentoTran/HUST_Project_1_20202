#ifndef _ADC_0804_H_
#define _ADC_0804_H_

#include "port.h"
#include "delay.h"

unsigned char ADC0804_Read(void);

float Cal_Temp(unsigned int ADC_Value);

#endif