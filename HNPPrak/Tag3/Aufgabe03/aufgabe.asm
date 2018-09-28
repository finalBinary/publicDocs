;
; Aufgabe 03
;

%include "asm_io.inc"
;
; initialized data is put in the .data segment
;
segment .data
;
; These labels refer to strings used for output
;
s1 db "Geben Sie die eine Zahl ein: ", 0

s2 db "Die Zahl ist durch drei Teilbar", 0
s3 db "Die Zahl ist nicht durch drei Teilbar", 0


;
; code is put in the .text segment
;
segment .text
    global asm_haupt 
asm_haupt:
    enter 0,0
    pusha
    
    xor ebx, ebx
    
    ; read input
    mov eax, s1
    call print_string
    call read_int
    
    ; divide
    cdq
    mov ebx, 3
    idiv ebx
    dump_regs 1 
    
    ;compare, and choose message
    cmp edx, 0
    JNE else_block
    mov eax, s2
	call print_string
	JMP end_if
		
    else_block:
		mov eax, s3
		call print_string
	
	end_if:
		call print_nl
    
    popa
    mov eax, 0 
    leave
    ret
