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
result  db      "The sum is ", 0
;*******************************************************


;*******************************************************
; reserve memory for variables
;
segment .bss
input   resd 1
;*******************************************************
 

;*******************************************************
; code is put in the .text segment
;
segment .text
        global  asm_main
asm_main:
        enter   0,0               ; setup routine
        pusha

        mov     edx, 1            ; edx is 'i' in pseudo-code
while_loop:
        push    edx               ; save i on stack
        push    dword input       ; push address on input on stack
        call    get_int
        add     esp, 8            ; remove i and &input from stack

        mov     eax, [input]
        cmp     eax, 0
        je      end_while

        add     [sum], eax        ; sum += input

        inc     edx
        jmp     short while_loop

end_while:
        push    dword [sum]       ; push value of sum onto stack
        call    print_sum
        pop     ecx               ; remove [sum] from stack

        popa
        leave                     
        ret


;============================================================

get_int:
	enter 0, 0
	pusha
	
	;print index
        mov     eax, [ebp + 12]
        call    print_int

	;print enter nr promt
        mov     eax, prompt
        call    print_string
        
	;read int
        call    read_int
        mov     ebx, [ebp + 8]	; load input variable adress to ebx
        mov     [ebx], eax	; store input into memory

	popa

	leave
        ret                    

;============================================================

print_sum:
        enter 0, 0
	pusha

	;print result promt
        mov     eax, result
        call    print_string

	;print sum
        mov     eax, [ebp+8]
        call    print_int
        call    print_nl

        popa
	leave
        ret






