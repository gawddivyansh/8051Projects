#include<reg52.h>

sbit count_T0=P3^4;

sbit RS=P2^0;
sbit RW=P2^1;
sbit E=P2^2;

void send_command(unsigned int command_value ) ;
void send_data(unsigned int data_value) ;
void ms_delay( unsigned int time);
unsigned char i;
unsigned int cnt_val;
void main()
{
		
//LCD INITIALIZATION

//2 lines and 5x7 matrix
send_command(0x38);

//display on cursor blink
send_command(0x0E);
	
//clear display screen
send_command(0X01);

// counter initialization
TMOD=0X06; //counter 0, mode 2, 8 bit mode
count_T0=1; // p3.4 input pin
	
while(1)
{
	
TH0=0x00;
TL0=0x00;	// count value initialize
	
TR0=1; //counter 0 on

while(!TF0) // monitoring TF0 flag
{
	send_command(0x80)	; // force cursor on 1st line and 1st col	
	
	cnt_val = TL0;	
  
	i = cnt_val/10; //Get the Ten's place
  //	 i + 0x30;			// Convert it to ASCII
  send_data(i + 0x30);			//Display Tens place
  	
	i = cnt_val%10 ;			//Get the unit place
  //	 i + 0x30; 			// Convert it to ASCII
  send_data(i + 0x30);	//Display unit place
	
	if (cnt_val == 100)   // restricting count 00 to 99
	{
		break;
	}
}

TF0=0;  //reset flag
TR0=0; //off counter 
}

}



void send_command(unsigned int command_value ) //send command to LCD
{
	P1=command_value;
	RW=0;
	RS=0;
	E=1;
	ms_delay(10);
	E=0;
}	

void send_data(unsigned int data_value) // send data to LCD
{
	P1=data_value;
	RW=0;
	RS=1;
	E=1;
	ms_delay(10);
	E=0;
}

void ms_delay( unsigned int time)   // delay generation
{
	unsigned int i,j;
	//time X 1ms
	for(i=0;i<time;i++)
	{
		for(j=0;j<113;j++);  //1 ms
	}
}


