%include "asm_io.inc"
segment .data

errorprompt db    "Sprung zum Label error erfolgt!", 0       

segment .text
        global  asm_main
asm_main:
        enter   0,0               ; Setup Routine
        pusha

a:      mov eax, 10 ;zero flag
        mov ebx, 10;hier ergaenzen
        ;mov ebx, 0;hier ergaenzen
        cmp eax, ebx
        jz b
        jmp error
        
b:      mov eax, 0x1 ;overflow flag
        mov ebx, 0x7FFFFFFF;hier ergaenzen
        ;mov ebx, 0x6FFFFFFF;hier ergaenzen
        add eax, ebx
        jo c
        jmp error
        
c:      mov eax, 0x2 ;signed flag
        mov ebx, 0xFFFFFFFF;hier ergaenzen
        ;mov ebx, 0xFFFFFFF;hier ergaenzen
        or eax, ebx
        js ende
        jmp error
        
error:  mov eax, errorprompt
        call print_string
        call print_nl

ende:   popa
        mov     eax, 0            ; Zurueck zu C
        leave
        ret


