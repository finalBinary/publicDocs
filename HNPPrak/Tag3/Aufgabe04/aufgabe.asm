;
; Aufgabe 04
;

%include "asm_io.inc"
;
; initialized data is put in the .data segment
;
segment .data
;
; These labels refer to strings used for output
;
s1 db "Die Summe ist: ", 0

;
; code is put in the .text segment
;
segment .text
    global asm_haupt 
asm_haupt:
    enter 0,0
    pusha
    
    mov ebx, 0
	mov ecx, 50
	loop_start:
		mov eax, ecx
		add eax, ecx
		
		add ebx, eax 
		loop loop_start
		
    
    
    ; write output
    mov eax, s1
    call print_string
    mov eax, ebx
    call print_int
    call print_nl
    
    
    popa
    mov eax, 0 
    leave
    ret
