
ORG 00H
	
MOV TMOD,#06h	  ; counter 0 MODE 2 8BIT auto reload mode

SETB P3.4   ;T0 input pin

MOV TL0,#00H
MOV TH0,#00H

HERE:SETB TR0   ;counter 0 on

BACK:MOV P1,TL0
JNB TF0,BACK

CLR TR0
CLR TF0

SJMP HERE

END