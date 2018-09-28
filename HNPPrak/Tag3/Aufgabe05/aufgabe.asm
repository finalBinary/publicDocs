;
; Aufgabe 05
;

%include "asm_io.inc"
;
; initialized data is put in the .data segment
;
segment .data
;
; These labels refer to strings used for output
;
s1 db "Geben Sie die erste Zahl ein: ", 0
s2 db "Geben Sie die zweite Zahl ein: ", 0
s3 db "Geben Sie die dritte Zahl ein: ", 0

s4 db "Die Checksumme ist: ", 0

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
    
    ; read second input
    mov eax, s2
    call print_string
    call read_int
    xor ebx, eax
    
    ; read third input
    mov eax, s3
    call print_string
    call read_int
    xor ebx, eax
    
    ; write output
    mov eax, s4
    call print_string
    mov eax, ebx
    call print_int
    call print_nl
    
    
    popa
    mov eax, 0 
    leave
    ret
