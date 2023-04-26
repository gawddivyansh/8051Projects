#include<reg52.h>

void ms_delay();

void main()
{
	
TMOD=0X01; //timer 0, mode 1, 16 bit mode
while(1)
{
P1=0XFF;
ms_delay();	
P1=0X00;
ms_delay();		
}
}


void ms_delay()   // 5ms
{	
TL0=0x00;           
TH0=0x0EE; // 5ms
	
TR0=1;
	
while(!TF0);
	
TR0=0; //timer off
TF0=0; 
}

