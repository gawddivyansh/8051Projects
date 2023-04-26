#include<reg51.h>

void ms_delay( unsigned int time);

void main()
{
	char DB[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67}; //common cathode
	unsigned char i;
	while(1)
	{
	for(i=0;i<10;i++)
	{
		P3=DB[i];
		ms_delay(1000);
	}
	}
}
void ms_delay( unsigned int time)
{
	unsigned int i,j;
	//time X 1ms
	for(i=0;i<time;i++)
	{
		for(j=0;j<113;j++);  //1 ms
	}
}