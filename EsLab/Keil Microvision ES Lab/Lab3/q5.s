        AREA RESET,DATA,READONLY
        EXPORT __Vectors
__Vectors
        DCD 0x40001000
        DCD Reset_Handler

        ALIGN
        AREA mycode, CODE, READONLY
        ENTRY
        EXPORT Reset_Handler
Reset_Handler
        LDR R0, =NUMBERS       ; Load address of the numbers array
        MOV R1, #10            ; Loop counter (10 numbers)
        MOV R2, #0             ; Initialize sum to 0

LOOP    
        LDR R3, [R0], #4       ; Load value from address in R0, then increment R0 by 4
        ADD R2, R2, R3         ; Add value to sum (R2)
        SUBS R1, R1, #1        ; Decrement counter
        BNE LOOP               ; Repeat until R1 == 0

        LDR R4, =RESULT        ; Load address of RESULT
        STR R2, [R4]           ; Store the sum in memory

STOP    B STOP                 ; Stop execution

NUMBERS DCD 1, 2, 3, 4, 5, 6, 7, 8, 9, 10  ; Array of 10 numbers

        AREA data,DATA,READWRITE
RESULT  DCD 0                 ; Store sum here

        END
