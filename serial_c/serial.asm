ORG 00H
	
MOV TMOD,#20h         ; timer1 mode2

MOV SCON,#50h           ; mode1 ren

MOV TH1,#0FDH       	  ;9600 baud rate

SETB TR1

//tx 
AGAIN:MOV SBUF,#'L'
HERE1:JNB TI, HERE1
CLR TI
MOV SBUF,#'A'
HERE2:JNB TI, HERE2
CLR TI
MOV SBUF,#'B'
HERE3:JNB TI, HERE3
CLR TI

//rx
HERE4:JNB RI, HERE4
MOV P1,SBUF
CLR RI
HERE5:JNB RI, HERE5
MOV P1,SBUF
CLR RI
SJMP AGAIN
END																																																																																																																		
																																																																																																																				
																																																																																																																				