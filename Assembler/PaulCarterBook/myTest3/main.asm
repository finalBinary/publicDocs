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
    global asm_main 
asm_main:
    enter 0,0
    pusha


    ; read input
    mov eax, s1
    call print_string
    call read_int
    mov ebx, eax

    ;8bit division, if ax > 65535 ax is 0000
    xor edx, edx	
    ;mov ax, 8
    mov bx, 2
    dump_regs 1	
    div bx
    dump_regs 1

    ;result 1
    call print_int ;if ax was > 65535 autput will be ax, since dax is printed
    call print_nl

    ;16bit division
    mov ax, 8 ;if ax was > 65535, the high bit of dax will remain
    dump_regs 1	
    cdq
    dump_regs 1	
    mov bx, 2
    div bx

    ;result 2
    call print_int
    call print_nl

    ; write output
    ;mov eax, s2
    ;call print_string
    ;mov eax, ebx
    ;call print_int
    ;call print_nl
    

    popa
    mov eax, 42 
    leave
    ret
