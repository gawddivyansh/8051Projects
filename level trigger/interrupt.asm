ORG 00H
		LJMP MAIN
ORG 0003H
	   	CPL P1.4
		ACALL Delay
		
		RETI

ORG 30H
MAIN:	MOV IE,#81H; ENABLE EINT0
		CLR IT0 ; level triggered
SETB P1.3
		ACALL Delay
		CLR P1.3
		ACALL Delay
		SJMP MAIN


DELAY:      MOV R0,#07
	   HERE3:MOV R1,#255
	   HERE2:MOV R2,#255
	   HERE1:DJNZ R2,HERE1
	         DJNZ R1,HERE2
	         DJNZ R0,HERE3
	   RET

END
