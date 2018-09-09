%include "asm_io.inc"
;
; initialized data is put in the .data segment
;
segment .data
;
; These labels refer to strings used for output
;
s1 db "Geben Sie eine Zahl ein: ", 0
s2 db "Das ist die Zahl, die Sie eingegeben haben: ", 0
;
; code is put in the .text segment
;
segment .text
    global asm_haupt 
asm_haupt:
    enter 0,0
    pusha
    ; read input
    mov eax, s1
    call print_string
    call read_int
    mov ebx, eax
    ; write output
    mov eax, s2
    call print_string
    mov eax, ebx
    call print_int
    call print_nl
    popa
    mov eax, 42 
    leave
    ret
