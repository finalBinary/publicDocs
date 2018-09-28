;
; psuedo-code algorithm
; i = 1;
; sum = 0;
; while( get_int(i, &input), input != 0 ) {
;   sum += input;
;   i++;
; }
; print_sum(num);

%include "asm_io.inc"

;*******************************************************
; initialized data is put in the .data segment
;
segment .data
sum     dd   0
prompt  db      ") Enter an integer number (0 to quit): ", 0
tab  db      " ", 0

result  db      "The sum is ", 0
;*******************************************************


;*******************************************************
; reserve memory for variables
;
segment .bss
input   resd 1
array	resd 10
;*******************************************************
 

;*******************************************************
; code is put in the .text segment
;
segment .text
        global  asm_main
asm_main:
        enter   0,0               ; setup routine
        pusha

        mov     edx, 0            ; edx is 'i' in pseudo-code
while_loop:
		
        
        call    read_char
        push	eax		; push input on stack
        call    read_char
        

        inc     edx
        cmp     edx, 10
        je      end_while
        jmp     while_loop

end_while:

		mov     edx, 0
second_while:

		
		pop 	eax
		
		call	print_char
		
		mov		eax, tab
		call	print_string
		
		pop 	eax
		
		
		inc     edx
        cmp     edx, 5
        je      end_second_while
        jmp     short second_while
        
end_second_while:

		call	print_nl


        popa
        leave                     
        ret
