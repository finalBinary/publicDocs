%include "asm_io.inc"
;
; initialized data is put in the .data segment
;
segment .data

segment .bss



; text segment was missing + secret_func was not declared global
segment .text
        global  secret_func

;The function calculates:
;
;int n secret_func(int n){
;        if(n == 1) return 1;
;        return secret_func(n-1) * n;
;}
secret_func:
        
       
        ; enter and pusha were missing to save crucial registers.
        ; Since the position of 'mov     eax, [ebp-4]' at the end
        ; is provided, popa will be omitted as it belongs bevor the
        ; instruction 'mov     eax, [ebp-4]' (see below for details)
        enter   4,0
        

        ; the input variable n was not obtained from the stack
        mov     eax, dword [ebp+8]
        ;pop     eax

        ;call print_int
        ;call print_nl

        cmp     eax, 1
        je      basecase

        sub     eax, 1
        push    eax
        call    secret_func
        add     esp, 4
        imul    eax, [ebp+8]    
        mov     [ebp-4], eax    ; return value in eax
        jmp end
        

basecase:
        mov     [ebp-4], dword 1

end:
        mov     eax, [ebp-4]   ; return value into eax

       

        ; popa leave and ret were missing for a clean function exit
        ; instead of pusha and popa the registers:
        ; EBX, ESI, EDI, CS, DS, SS, ES could also be pushed seperatly.
        ; Since the mentioned registers are not changed here, pushig
        ; and poping can be neglected, although it wouldnt hurt.

        leave
        ret