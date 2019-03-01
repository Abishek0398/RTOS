    PRESERVE8
	THUMB
    AREA    |.text|, CODE, READONLY
	EXTERN current_tcb
	EXTERN new_high_tcb
context_switch PROC
	EXPORT context_switch
    LDR     R0, =0xE000ED04
    LDR     R1, =0x10000000   
    STR     R1, [R0]
    BX      LR
	ENDP

PendSV_Handler PROC
	EXPORT PendSV_Handler
    CPSID   I                                                   ; Prevent interruption during context switch
    MRS     R0, PSP                                             ; PSP is process stack pointer
    STMFD   R0!, {R4-R11}                                       ; Save remaining regs r4-11 on process stack

    MOV32   R5, current_tcb                                     ; OSTCBCurPtr->OSTCBStkPtr = SP;
    LDR     R6, [R5]
    STR     R0, [R6]                                            ; R0 is SP of process being switched out

                                                                ; At this point, entire context of process has been saved      

    MOV32   R1, new_high_tcb                                 ; OSTCBCurPtr = OSTCBHighRdyPtr;
    LDR     R2, [R1]
    STR     R2, [R5]
    ORR     LR, R4, #0xF4
    LDR     R0, [R2]                                            ; R0 is new process SP; SP = OSTCBHighRdyPtr->StkPtr;
    LDMFD   R0!, {R4-R11}                                       ; Restore r4-11 from new process stack
    MSR     PSP, R0                                             ; Load PSP with new process SP
    CPSIE   I
    BX      LR 
    ENDP	

    END

