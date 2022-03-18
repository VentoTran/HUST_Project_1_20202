#include "port.h"
#include "LCD1602.h"
#include "ADC0804.h"
#include "HS1101.h"
#include "stdio.h"


unsigned int ADC_Value = 0;
unsigned int Frequency = 0;
double Temperature = 0.0;
unsigned short Humidity = 0;

unsigned char a[5];
unsigned char buffer[20];

void uart_init();

/*
unsigned int HS1101[101] = {
														7410, 7392, 7374, 7357, 7340, 7323, 7307, 7290, 7274, 7259, 
														7243, 7228, 7213, 7198, 7183 ,7169, 7155, 7140, 7127, 7113, 
														7099, 7086, 7072, 7059, 7046, 7033, 7020, 7007, 6995, 6982, 
														6969, 6957, 6945, 6932, 6920, 6908, 6896, 6884, 6872, 6860, 
														6848, 6836, 6824, 6812, 6800, 6788, 6776, 6764, 6752, 6740, 
														6728, 6716, 6704, 6692, 6680, 6668, 6656, 6643, 6631, 6619, 
														6606, 6594, 6581, 6568, 6556, 6543, 6530, 6517, 6504, 6491, 
														6477, 6464, 6450, 6437, 6423, 6409, 6395, 6381, 6367, 6352, 
														6338, 6323, 6309, 6294, 6279, 6264, 6248, 6233, 6217, 6202, 
														6186, 6170, 6154, 6137, 6121, 6104, 6087, 6070, 6053, 6036, 6019};
*/



void main(void)
{
	TMOD = 0X51;
	LCD_Init();
	setCursor(3, 0);
	printStrg("PROJECT_1");
	setCursor(2, 1);
	printStrg("MINH - DUNG");
	delay(1000);
	LCD_Clr();
	uart_init();
	
	while(1)
	{
		LED = 0;
		setCursor(0, 0);
		ADC_Value = ADC0804_Read();
		Temperature = Cal_Temp(ADC_Value);
		//sprintf(a, "%2.1f", Temperture);
		sprintf(a, "%3i", ADC_Value);
		putchar('a');
//		printStrg("Temp: ");
//		printStrg(a);
		/*
		if(ADC_Value <= 30)
		{
			setCursor(9, 1);
			printChar(0xDF);
			printStrg("C ");
		}
		else
		{
			printChar(0xDF);
			printChar('C');
		}
		*/
//		LED = 1;
//		setCursor(0, 1);
//		Frequency = Get_Freq();
//		Humidity = Get_Humd(Frequency);
//		printStrg("Humidity: ");
//		//sprintf(a, "%2d", Humidity);
//		sprintf(a, "%5d", Frequency);
//		printStrg(a);
//		//printChar('%');
//		
//		
//		delay(500);
		
	}
	
}

void uart_init()
{
	SCON = 0x52; //Uart mode 1
	T2CON = 0x20;			//Timer 1 autoreload mode
	TCLK = 1; RCLK =1; //choose timer 2 for two transmission lines
	RCAP2H = 0;				//baudrate 9600
	RCAP2L = -36;
	TR2 = 1;
	IE = 0x90;
	
}	

void comPortInterrupt(void) interrupt 4
{
	char receivedData = SBUF;
	IE = 0x00;
	if (receivedData == '$')
	{
		if (Temperature && Humidity)
		{
			sprintf(buffer, "%3f,", Temperature);
			sprintf(buffer, "%2d", Humidity);
			printf(buffer);	
		}	
	}
	RI = 0;
	IE = 0x90;
}	



