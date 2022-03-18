#include "ADC0804.h"


unsigned char ADC0804_Read(void)
{
	unsigned char result;
	
	ADC0804_CS = 0;
	
	ADC0804_WR = 0;
	ADC0804_WR = 1;
	
	while(ADC0804_INTR);
	
	ADC0804_RD = 0;
	result = ADC0804_Data;
	ADC0804_RD = 1;
	
	
	return result;
}


float Cal_Temp(unsigned int ADC_Value)
{
	float Temperature = 0.0;
	unsigned int frac = 0;
	unsigned int temp = 0;
	
	if (ADC_Value < 29)
		Temperature = (ADC_Value - 11) / 1.86982;
	else if ((ADC_Value >= 30) && (ADC_Value < 52))
		Temperature = (ADC_Value - 30) / 2.24137 + 10;
	else if ((ADC_Value >= 52) && (ADC_Value < 78))
		Temperature = (ADC_Value - 52) / 2.59323 + 20;
	else if ((ADC_Value >= 78) && (ADC_Value < 104))
		Temperature = (ADC_Value - 78) / 2.57189 + 30;
	else if ((ADC_Value >= 104) && (ADC_Value < 127))
		Temperature = (ADC_Value - 104) / 2.33659 + 40;
	else if ((ADC_Value >= 127) && (ADC_Value < 156))
		Temperature = (ADC_Value - 127) / 2.91112 + 50;
	else if ((ADC_Value >= 156) && (ADC_Value < 181))
		Temperature = (ADC_Value - 156) / 2.50075 + 60;
	else if ((ADC_Value >= 181) && (ADC_Value < 208))
		Temperature = (ADC_Value - 181) / 2.63397 + 70;
	else if ((ADC_Value >= 208) && (ADC_Value < 231))
		Temperature = (ADC_Value - 208) / 2.35803 + 80;
	
	else if ((ADC_Value >= 231) && (ADC_Value < 255))
		Temperature = (ADC_Value - 231) / 2.31705 + 90;
	
	temp = (unsigned int)(Temperature * 10);
	Temperature = (double)temp / 10;
	frac = temp % 10;

	if (frac < 3)
	{
		Temperature -= (double)(frac) / 10;
	}
	else if ((frac >= 3) && (frac <= 7))
	{
		Temperature += (5 - (double)frac) / 10;
	}
	else
	{
		Temperature += (double)(10 - frac) / 10;
	}
	
	return Temperature;
}

