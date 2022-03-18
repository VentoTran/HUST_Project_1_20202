#include "delay.h"
#include "port.h"
#include "LCD1602.h"
#include "ADC0804.h"
#include "HS1101.h"
#include "stdio.h"


unsigned int ADC_Value = 0;
unsigned int Frequency = 0;

double Temperature = 0;
unsigned short Humidity = 0;

unsigned short data_request = 0;

unsigned char a[5];
unsigned char buffer[20];

void uart_init(void);
void send_data(void);

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
	uart_init();
	TMOD = 0X51;
	LCD_Init();
	
	setCursor(3, 0);
	printStrg("PROJECT 1");
	setCursor(2, 1);
	printStrg("MINH - DUNG");
	delay(2000);
	LCD_Clr();
	
	
	while(1)
	{
		
		LED = 0;
		setCursor(0, 0);
		ADC_Value = ADC0804_Read();
		Temperature = Cal_Temp(ADC_Value);
		sprintf(a, "%3.1f", Temperature);
		//sprintf(a, "%3i", ADC_Value);
		printStrg("Temp: ");
		printStrg(a);
		
		if(Temperature >= 10.0)
		{
			printChar(0xDF);
			printChar('C');
		}
		else
		{
			setCursor(9, 0);
			printChar(0xDF);
			printStrg("C ");
		}
		
		
		LED = 1;
		setCursor(0, 1);
		Frequency = Get_Freq() - 1400;
		Humidity = Get_Humd(Frequency);
		printStrg("Humidity: ");
		sprintf(a, "%3d", Humidity);
		//sprintf(a, "%5d", Frequency);
		printStrg(a);
		printChar('%');
		
		if(data_request)
		{
			data_request = 0;
			send_data();
		}
		
		delay(50);
	}	
}

void uart_init()
{
	SCON = 0x52; 	//Uart mode 1
	T2CON = 0x30;	//Timer 2 autoreload mode
	//TCLK = 1; 
	//RCLK = 1; 		//choose timer 2 for two transmission lines
	RCAP2L = -36;	//baudrate 9600
	RCAP2H = 255;
	TR2 = 1;
	
	IE = 0x90;
}	

void comPortInterrupt(void) interrupt 4
{
	if (RI == 1)
	{
		char receivedData = SBUF;
		IE = 0x00;
		if (receivedData == '$')
		{	
		  data_request = 1;
		}
		RI = 0;
		IE = 0x90;
	}
}

void send_data(void)
{
	int buff = 0;		//to store index of buffer
	
	buff = sprintf(buffer, "%.1f,", Temperature);
	sprintf(buffer + buff, "%d\0", Humidity);
	printf(buffer);	
}	





