;
; Aufgabe 01
;
%include "asm_io.inc"
;
; initialized data is put in the .data segment
;
segment .data
;
; These labels refer to strings used for output
;
s1 db "Hello, World!", 0
; code is put in the .text segment
;
segment .text
    global asm_haupt 
asm_haupt:
    enter 0,0
    pusha
    
    
    mov eax, s1
    call print_string
    call print_nl
    
    
    popa
    mov eax, 0 
    leave
    ret
