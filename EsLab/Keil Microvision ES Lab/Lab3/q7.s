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
        LDR R0, =VALUE1       ; Load address of VALUE1
        LDR R1, [R0]          ; Load VALUE1 into R1 (A)

        LDR R0, =VALUE2       ; Load address of VALUE2
        LDR R2, [R0]          ; Load VALUE2 into R2 (B)

        MOV R3, R1            ; Copy A to R3 (for LCM calculation)
        MOV R4, R2            ; Copy B to R4 (for LCM calculation)

        ; Compute GCD using Euclidean Algorithm
GCD_LOOP
        CMP R1, R2            ; Compare A and B
        BEQ GCD_DONE          ; If A == B, GCD found
        BHI SUB_A             ; If A > B, subtract B from A
        SUB R2, R2, R1        ; Else, subtract A from B
        B GCD_LOOP

SUB_A
        SUB R1, R1, R2        ; A = A - B
        B GCD_LOOP

GCD_DONE
        ; Store GCD result
        LDR R0, =GCD_RESULT
        STR R1, [R0]          ; Store GCD (R1 now holds GCD)

        ; Compute LCM = (A * B) / GCD
        MUL R5, R3, R4        ; R5 = A * B
        UDIV R6, R5, R1       ; R6 = (A * B) / GCD

        ; Store LCM result
        LDR R0, =LCM_RESULT
        STR R6, [R0]          ; Store LCM result

STOP    B STOP

        AREA data,DATA,READWRITE
VALUE1  DCD 12               ; First 8-bit number
VALUE2  DCD 18               ; Second 8-bit number
GCD_RESULT DCD 0             ; Store GCD result
LCM_RESULT DCD 0             ; Store LCM result

        END
