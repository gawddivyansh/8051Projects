#include<reg52.h>

sbit count_T0=P3^4;

void main()
{
	
TMOD=0X06; //counter 0, mode 2, 8 bit mode
	
count_T0=1; // p3.4 input pin
	
while(1)
{
	
TH0=0x00;
TL0=0x00;	
	
TR0=1; //counter 0 on
	
while(!TF0)
{
P1=TL0;
}

TF0=0;
TR0=0; //off counter 
}

}

