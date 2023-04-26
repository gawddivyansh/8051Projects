ORG 00H

MOV  TMOD, #01H // mode1 16 bit timer// timer 0 
again1: 

MOV P1, #0FFH
ACALL DELAY
MOV P1, #00H
ACALL DELAY

SJMP again1


//5ms
DELAY: 	 MOV TL0, #00H 
MOV TH0, #0EEH 
SETB TR0 //turn on timer0
again: JNB TF0, again //jump if bit is not set
CLR TR0//turn off timer
CLR TF0
RET


END
