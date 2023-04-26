#include<reg51.h>
sbit ADDR_A = P3^0;
sbit ADDR_B = P3^1;
sbit ADDR_C = P3^2;
sbit ALE = P3^3;
sbit START = P3^4;
sbit OE = P3^5;
sbit EOC = P3^6;
#define  ADC_DATA P2
#define  LED_OUT P1
sbit clk = P3^7;

// Generate square wave of 100 KHz
void timer0() interrupt 1
{
	clk = ~clk;
	TF0 = 0;
}

void main()
	{
		TMOD = 0x02; //timer 0 auto reload mode 8 bit timer
		TH0 = 0xFA;  //auto reload value
		IE = 0x82;   // enable timer0 overflow interrupt
		TR0 = 1;     // start timer 0
		P2 = 0xff;   //Port 2 as input port
		P1 = 0x00;   // Port 1 as output
		P3 = 0x40	;  // set all pins of port 3 as output except P3.6
		
while(1)
{	
	  //Select IN1 as input source
		ADDR_A = 1; 
		ADDR_B = 0;
		ADDR_C = 0;
		ALE = 1;   // latch address
		START = 1; // start conversion 
    ALE	= 0;   //latch address
		START = 0; // start conversion 
	//Check for end of conversion
	  while(EOC == 1);
	  while(EOC == 0);
		OE = 1;    // Set the output enable
	  LED_OUT = ADC_DATA; // Show the result on LED_OUT's
	  OE = 0;    // Set the output disable
}
}