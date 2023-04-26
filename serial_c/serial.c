#include <reg52.h>

void main()
{
TMOD = 0x20;         // timer1 mode2

SCON=0x50 ;          // mode1 ren

TH1=0x0FD  ;     	  //9600 baud rate

TR1=1; //on timer1 

//tx 
while(1)
{
SBUF ='L';
while(!TI);
TI=0;
	
SBUF ='A';
while(!TI);
TI=0;
	
SBUF ='B';
while(!TI);
TI=0;
	

//rx
while(!RI);
P1=SBUF;
RI=0;
	
while(!RI);
P1=SBUF;
RI=0;

}
	
}
																																																																																																																				
																																																																																																																				