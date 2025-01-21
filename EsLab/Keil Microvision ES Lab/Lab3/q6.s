		AREA RESET,DATA,READONLY
		EXPORT __Vectors
		
__Vectors
		DCD 0x40001000
		DCD Reset_Handler
			
		ALIGN
		AREA mycode,CODE,READONLY
		ENTRY
		EXPORT Reset_Handler
Reset_Handler
		LDR R0, =FIB_SERIES
		MOV R1,#0	; First Fibonacci number (F(0) = 0)
		MOV R2,#1	; Second Fibonacci number (F(1) = 1)
		MOV R3,#10	; Number of terms to generate
		
		STR R1,[R0],#4	; Store F(0) at memory location and increment R0
		STR R2,[R0],#4	; Store F(1) at next memory location and increment R0
		SUBS R3,R3,#2	; Reduce loop counter (since first two values are already stored)

LOOP
		ADD R4,R1,R2	; Compute next Fibonacci number
		STR R4,[R0],#4  ; Store computed Fibonacci number in memory
		MOV R1, R2      ; Update F(n-2) = F(n-1)
		MOV R2, R4      ; Update F(n-1) = F(n)
		SUBS R3,R3,#1
		BNE LOOP

STOP
		B STOP

		AREA data,DATA,READWRITE
		        
FIB_SERIES  SPACE 40   ; Reserve space for 10 Fibonacci numbers (10 × 4 bytes = 40 bytes)

		END
