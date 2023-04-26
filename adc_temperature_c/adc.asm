										  
ADDR_A	EQU 		P3.0
ADDR_B	EQU 		P3.1
ADDR_C	EQU 		P3.2
ALE		EQU 		P3.3	
START	EQU 		P3.4
OE		EQU 		P3.5
EOC		EQU 		P3.6
ADC_DATA	EQU 		P2
LED_OUT	EQU			P1

		ORG 00H
		LJMP MAIN

		ORG 000BH
	   	CPL P3.7
		CLR TF0
		RETI
		
		ORG 0030H 		
MAIN: 	MOV TMOD, #02H  ; timer 0 auto reload mode 8 bit timer
		mov TH0, #0FBH  ; auto reload value
		MOV IE, #82H    ; enable timer0 overflow interrupt
		SETB TR0        ; start timer 0
		MOV P2,#0FFH	; Port 2 as input port
		mov P1,#00H     ; Port 1 as output port
		MOV P3,#40H	    ; Port 3 as output port except P3.6 
		// Select IN1 as input source
		SETB ADDR_A		; Select IN1 as input source
		CLR ADDR_B
		CLR ADDR_C

BACK:	
		SETB ALE		; latch address trigger
		SETB START      ; start conversion trigger
		CLR ALE			; latch address stop
		CLR START       ; start conversion stop
		
        // Check for end of conversion
HERE: 	JB EOC,HERE
HERE1:	JNB EOC, HERE1

		SETB OE			; Set the output enable
		MOV LED_OUT, ADC_DATA	; Get digital data output ion led
		CLR OE          ; clear the output enable
		SJMP BACK		; take another reading.

 
