%include "asm_io.inc"
;
; initialized data is put in the .data segment
;
segment .data

segment .bss

/**************************************************************/
/*                      Hier fehlt etwas.                     */
/**************************************************************/

secret_func:
        /**************************************************************/
        /* Hier fehlt etwas. Beachten Sie, dass der Übergabeparameter */
        /* für die Berechnung in eax vorhanden sein muss.             */
        /**************************************************************/

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

        /**************************************************************/
        /*                      Hier fehlt etwas.                     */
        /**************************************************************/
