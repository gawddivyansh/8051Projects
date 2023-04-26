#include<reg52.h>

//    RS     RW     E       D0 -  D7
//   P2.0   P2.1   P2.2   P1.0 - P1.7
//#define
sbit RS=P2^0;
sbit RW=P2^1;
sbit E=P2^2;

void send_command(unsigned int command_value ) ;
void send_data(unsigned int data_value) ;
void ms_delay( unsigned int time);

void main()
{
	
//LCD INITIALIZATION

//2 lines and 5x7 matrix
send_command(0x38);

//display on cursor blink
send_command(0x0E);

//clear display screen
send_command(0X01);




//PRINTING A CHARACTER

while(1)
{

send_command(0x80)	; // force cursor on 1st line		
send_data('E');
send_data('M');
send_data('B');
send_data('E');
send_data('D');
send_data('D');
send_data('E');
send_data('D');
	
send_command(0xC0)	; // force cursor on 2nd line	
	
send_data('L');
send_data('A');
send_data('B');	

}

}



void send_command(unsigned int command_value ) 
{
	P1=command_value;
	RW=0;
	RS=0;
	E=1;
	ms_delay(10);
	E=0;
}	

void send_data(unsigned int data_value) 
{
	P1=data_value;
	RW=0;
	RS=1;
	E=1;
	ms_delay(10);
	E=0;
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

