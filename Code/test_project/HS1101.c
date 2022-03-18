#include "HS1101.h"


unsigned int Get_Freq(void)
{
	unsigned int result = 0;
	TL1 = 0;
	TH1 = 0;  
	TR1 = 1;
  delay(100);
	TR1 = 0;
	result = TH1 * 256 + TL1;
	result *= 10;
	
	return result;
	
}

unsigned short Get_Humd(unsigned int Frequency)
{
	unsigned short Humidity = 0;
	//100
	if (Frequency <= 6019)
		Humidity = 100;
	
	//100 -> 91
	else if ((Frequency <= 6036) && (Frequency >= 6019))
		Humidity = 100;
	else if ((Frequency <= 6053) && (Frequency >= 6036))
		Humidity = 99;
	else if ((Frequency <= 6070) && (Frequency >= 6053))
		Humidity = 98;
	else if ((Frequency <= 6087) && (Frequency >= 6070))
		Humidity = 97;
	else if ((Frequency <= 6104) && (Frequency >= 6087))
		Humidity = 96;
	else if ((Frequency <= 6121) && (Frequency >= 6104))
		Humidity = 95;
	else if ((Frequency <= 6137) && (Frequency >= 6121))
		Humidity = 94;
	else if ((Frequency <= 6154) && (Frequency >= 6137))
		Humidity = 93;
	else if ((Frequency <= 6170) && (Frequency >= 6154))
		Humidity = 92;
	else if ((Frequency <= 6186) && (Frequency >= 6170))
		Humidity = 91;
	
	//90 -> 81
	else if ((Frequency <= 6202) && (Frequency >= 6186))
		Humidity = 90;
	else if ((Frequency <= 6217) && (Frequency >= 6202))
		Humidity = 89;
	else if ((Frequency <= 6233) && (Frequency >= 6217))
		Humidity = 88;
	else if ((Frequency <= 6248) && (Frequency >= 6233))
		Humidity = 87;
	else if ((Frequency <= 6264) && (Frequency >= 6248))
		Humidity = 86;
	else if ((Frequency <= 6279) && (Frequency >= 6264))
		Humidity = 85;
	else if ((Frequency <= 6294) && (Frequency >= 6279))
		Humidity = 84;
	else if ((Frequency <= 6309) && (Frequency >= 6294))
		Humidity = 83;
	else if ((Frequency <= 6323) && (Frequency >= 6309))
		Humidity = 82;
	else if ((Frequency <= 6338) && (Frequency >= 6323))
		Humidity = 81;
	
	//80 -> 71
	else if ((Frequency <= 6352) && (Frequency >= 6338))
		Humidity = 80;
	else if ((Frequency <= 6367) && (Frequency >= 6352))
		Humidity = 79;
	else if ((Frequency <= 6381) && (Frequency >= 6367))
		Humidity = 78;
	else if ((Frequency <= 6395) && (Frequency >= 6381))
		Humidity = 77;
	else if ((Frequency <= 6409) && (Frequency >= 6395))
		Humidity = 76;
	else if ((Frequency <= 6423) && (Frequency >= 6409))
		Humidity = 75;
	else if ((Frequency <= 6437) && (Frequency >= 6423))
		Humidity = 74;
	else if ((Frequency <= 6450) && (Frequency >= 6437))
		Humidity = 73;
	else if ((Frequency <= 6464) && (Frequency >= 6450))
		Humidity = 72;
	else if ((Frequency <= 6477) && (Frequency >= 6464))
		Humidity = 71;
	
	//70 -> 61
	else if ((Frequency <= 6491) && (Frequency >= 6477))
		Humidity = 70;
	else if ((Frequency <= 6504) && (Frequency >= 6491))
		Humidity = 69;
	else if ((Frequency <= 6517) && (Frequency >= 6504))
		Humidity = 68;
	else if ((Frequency <= 6530) && (Frequency >= 6517))
		Humidity = 67;
	else if ((Frequency <= 6543) && (Frequency >= 6530))
		Humidity = 66;
	else if ((Frequency <= 6556) && (Frequency >= 6543))
		Humidity = 65;
	else if ((Frequency <= 6568) && (Frequency >= 6556))
		Humidity = 64;
	else if ((Frequency <= 6581) && (Frequency >= 6568))
		Humidity = 63;
	else if ((Frequency <= 6594) && (Frequency >= 6581))
		Humidity = 62;
	else if ((Frequency <= 6606) && (Frequency >= 6594))
		Humidity = 61;
	
	//60 -> 51
	else if ((Frequency <= 6619) && (Frequency >= 6606))
		Humidity = 60;
	else if ((Frequency <= 6631) && (Frequency >= 6619))
		Humidity = 59;
	else if ((Frequency <= 6643) && (Frequency >= 6631))
		Humidity = 58;
	else if ((Frequency <= 6656) && (Frequency >= 6643))
		Humidity = 57;
	else if ((Frequency <= 6668) && (Frequency >= 6656))
		Humidity = 56;
	else if ((Frequency <= 6680) && (Frequency >= 6668))
		Humidity = 55;
	else if ((Frequency <= 6692) && (Frequency >= 6680))
		Humidity = 54;
	else if ((Frequency <= 6704) && (Frequency >= 6692))
		Humidity = 53;
	else if ((Frequency <= 6716) && (Frequency >= 6704))
		Humidity = 52;
	else if ((Frequency <= 6728) && (Frequency >= 6716))
		Humidity = 51;

	
	//50 -> 41
	else if ((Frequency <= 6740) && (Frequency >= 6728))
		Humidity = 50;
	else if ((Frequency <= 6752) && (Frequency >= 6740))
		Humidity = 49;
	else if ((Frequency <= 6764) && (Frequency >= 6752))
		Humidity = 48;
	else if ((Frequency <= 6776) && (Frequency >= 6764))
		Humidity = 47;
	else if ((Frequency <= 6788) && (Frequency >= 6776))
		Humidity = 46;
	else if ((Frequency <= 6800) && (Frequency >= 6788))
		Humidity = 45;
	else if ((Frequency <= 6812) && (Frequency >= 6800))
		Humidity = 44;
	else if ((Frequency <= 6824) && (Frequency >= 6812))
		Humidity = 43;
	else if ((Frequency <= 6836) && (Frequency >= 6824))
		Humidity = 42;
	else if ((Frequency <= 6848) && (Frequency >= 6836))
		Humidity = 41;
	
	//40 -> 31
	else if ((Frequency <= 6860) && (Frequency >= 6848))
		Humidity = 40;
	else if ((Frequency <= 6872) && (Frequency >= 6860))
		Humidity = 39;
	else if ((Frequency <= 6884) && (Frequency >= 6872))
		Humidity = 38;
	else if ((Frequency <= 6896) && (Frequency >= 6884))
		Humidity = 37;
	else if ((Frequency <= 6908) && (Frequency >= 6896))
		Humidity = 36;
	else if ((Frequency <= 6920) && (Frequency >= 6908))
		Humidity = 35;
	else if ((Frequency <= 6932) && (Frequency >= 6920))
		Humidity = 34;
	else if ((Frequency <= 6945) && (Frequency >= 6932))
		Humidity = 33;
	else if ((Frequency <= 6957) && (Frequency >= 6945))
		Humidity = 32;
	else if ((Frequency <= 6969) && (Frequency >= 6957))
		Humidity = 31;
	
	//30 -> 21
	else if ((Frequency <= 6982) && (Frequency >= 6969))
		Humidity = 30;
	else if ((Frequency <= 6995) && (Frequency >= 6982))
		Humidity = 29;
	else if ((Frequency <= 7007) && (Frequency >= 6995))
		Humidity = 28;
	else if ((Frequency <= 7020) && (Frequency >= 7007))
		Humidity = 27;
	else if ((Frequency <= 7033) && (Frequency >= 7020))
		Humidity = 26;
	else if ((Frequency <= 7046) && (Frequency >= 7033))
		Humidity = 25;
	else if ((Frequency <= 7059) && (Frequency >= 7046))
		Humidity = 24;
	else if ((Frequency <= 7072) && (Frequency >= 7059))
		Humidity = 23;
	else if ((Frequency <= 7086) && (Frequency >= 7072))
		Humidity = 22;
	else if ((Frequency <= 7099) && (Frequency >= 7086))
		Humidity = 21;
	
	//20 -> 11
	else if ((Frequency <= 7113) && (Frequency >= 7099))
		Humidity = 20;
	else if ((Frequency <= 7127) && (Frequency >= 7113))
		Humidity = 19;
	else if ((Frequency <= 7140) && (Frequency >= 7127))
		Humidity = 18;
	else if ((Frequency <= 7155) && (Frequency >= 7140))
		Humidity = 17;
	else if ((Frequency <= 7169) && (Frequency >= 7155))
		Humidity = 16;
	else if ((Frequency <= 7183) && (Frequency >= 7169))
		Humidity = 15;
	else if ((Frequency <= 7195) && (Frequency >= 7183))
		Humidity = 14;
	else if ((Frequency <= 7213) && (Frequency >= 7195))
		Humidity = 13;
	else if ((Frequency <= 7228) && (Frequency >= 7213))
		Humidity = 12;
	else if ((Frequency <= 7243) && (Frequency >= 7228))
		Humidity = 11;
	
	//10 -> 1
	else if ((Frequency <= 7259) && (Frequency >= 7243))
		Humidity = 10;
	else if ((Frequency <= 7274) && (Frequency >= 7259))
		Humidity = 9;
	else if ((Frequency <= 7290) && (Frequency >= 7274))
		Humidity = 8;
	else if ((Frequency <= 7307) && (Frequency >= 7290))
		Humidity = 7;
	else if ((Frequency <= 7323) && (Frequency >= 7307))
		Humidity = 6;
	else if ((Frequency <= 7340) && (Frequency >= 7323))
		Humidity = 5;
	else if ((Frequency <= 7357) && (Frequency >= 7340))
		Humidity = 4;
	else if ((Frequency <= 7374) && (Frequency >= 7357))
		Humidity = 3;
	else if ((Frequency <= 7392) && (Frequency >= 7374))
		Humidity = 2;
	else if ((Frequency <= 7410) && (Frequency >= 7392))
		Humidity = 1;
	
	//0
	else if (Frequency >= 7410)
		Humidity = 0;
	
	
	return Humidity;
	
}

