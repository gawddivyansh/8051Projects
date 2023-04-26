#include <reg52.h>
void main()
{
unsigned char temp;
TMOD = 0x20; // timer1 mode2
SCON=0x50 ; // mode1 r-en
TH1=0x0FD ; //9600 baud rate
TR1=1; //on timer1 
P1=0x00; // port 1 off
while(1)
{
//rx
while(!RI); // wait till RI become 1 
temp=SBUF; // collect received data into variable temp
RI=0; // Clear RI flag
if (temp=='1')
{
P1=(0X01<<4); // LED1 glow
}
else if (temp=='2')
{
P1=(0X01<<5); // LED1 glow
}
else if (temp=='3')
{
P1=(0X01<<6); // LED1 glow
}
else if (temp=='4')
{
P1=(0X01<<7); // LED1 glow
}
else if (SBUF=='5')
{
P1=(0X00); // LED1 off
}
}
}