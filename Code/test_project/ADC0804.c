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
	float Temperture = 0.0;
	
	if(ADC_Value <= 30)
		Temperture = (ADC_Value - 3) / 2.72569;
	else if ((ADC_Value > 30) && (ADC_Value <= 57))
		Temperture = (ADC_Value - 30) / 2.67593 + 10;
	else if ((ADC_Value > 57) && (ADC_Value <= 83))
		Temperture = (ADC_Value - 57) / 2.62699 + 20;
	else if ((ADC_Value > 83) && (ADC_Value <= 109))
		Temperture = (ADC_Value - 83) / 2.57922 + 30;
	else if ((ADC_Value > 109) && (ADC_Value <= 134))
		Temperture = (ADC_Value - 109) / 2.5326 + 40;
	else if ((ADC_Value > 134) && (ADC_Value <= 159))
		Temperture = (ADC_Value - 134) / 2.48723 + 50;
	else if ((ADC_Value > 159) && (ADC_Value <= 183))
		Temperture = (ADC_Value - 159) / 2.44307 + 60;
	else if ((ADC_Value > 183) && (ADC_Value <= 207))
		Temperture = (ADC_Value - 183) / 2.39995 + 70;
	else if ((ADC_Value > 207) && (ADC_Value <= 231))
		Temperture = (ADC_Value - 207) / 2.35803 + 80;
	else if ((ADC_Value > 231) && (ADC_Value <= 255))
		Temperture = (ADC_Value - 231) / 2.31705 + 90;

	return Temperture;
}

