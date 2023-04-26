ORG 00h ;The ORG directive is used to indicate the beginning of the address
		;The number that comes after ORG can be either in hex and decimal
		;If the number is not followed by H, it is decimal and the assembler will convert it to hex


HERE:	MOV P1,#0FFH   ; led P1
		LCALL DELAY
		MOV P1,#00H
		LCALL DELAY
	    SJMP HERE


; delay = 2 x 7 x 255 x 255 x 1.085us = 0.99 s
DELAY: 	MOV R0,#07
HERE3:	MOV R1,#255
HERE2:	MOV R2,#255
HERE1:	DJNZ R2,HERE1
		DJNZ R1,HERE2
		DJNZ R0,HERE3
	 
   	    RET

 END
 ;This indicates to the assembler the end of the source (asm) file
 ;The END directive is the last line of an 8051 program
 ;Mean that in the code anything after the END directive is ignored by the assembler
