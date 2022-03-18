#include "delay.h"


void delay(unsigned short z)
{
  unsigned short i;
  for(i = 0; i < z; i++)    
  {
		TH0 = 0xFC;
		TL0 = 0x6A;
		TR0 = 1;
		while(TF0 == 0);
		TF0 = 0;
		TR0 = 0;
  }
}