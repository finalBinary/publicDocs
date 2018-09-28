%include "asm_io.inc"
segment .text
    global asm_main

asm_main:
    enter 0,0
    pusha
    
    mov eax, 3
    push eax
    
    call calc
    add esp, 4
    
    call print_int
    call print_nl

    ; Geben Sie den Stack direkt vor dem popa Befehl an.
    popa
    mov eax, 0
    leave
    ret


;int function calc(int n){
;	if(ebx == 1){
;		return 1;
;	} else {
;		return calc(n-1) + n/2
;	}
;}
calc:
    enter 4,0   ; lokale Variable fuer Ergebnissicherung
    pusha		; !!Corrected
    
    ; Geben Sie den Stack immer direkt vor dem mov Befehl an. 
    ; Korrigieren Sie aber zuerst den Fehler.
    mov ebx, [ebp+8] ; Parameter in ebx
    
    ;Basecase
    mov eax, 1      
    cmp eax, ebx
    je end_calc
    
    ; Rekursionsvorschrift
    mov eax, ebx
    sub eax, 1
    
    push eax
    call calc
    add esp, 4

    ; Geben Sie den Stack an dieser Stelle einmalig bei der Rückkehr aus calc(1) an.


    shr ebx, 1
    add eax, ebx
    ;Berechnung beendet
    
end_calc:
    mov [ebp-4], eax
    
    popa		; !!Corrected
    mov eax, [ebp-4]
    leave
    ret
