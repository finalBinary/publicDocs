%include "asm_io.inc"

segment .data

open	db 	"[", 0
space	db	", ", 0
close	db	"]", 0


segment .text
        global  print_char_array

print_char_array:
        enter   4,0             ; allocate room for sum on stack
        pusha

	mov	ecx, [ebp+8]	; ecx = len of array
	sub	ecx, 1		; ecx = ecx -1
        mov     [ebp-4], ecx    ; n = length of array - 1

	mov	edx, [ebp+12]	;array head pointer to edx
	

	mov	eax, open
	call	print_string

        mov     ecx, 0            ; ecx is i of loop
for_loop:
        cmp     ecx, [ebp-4]      ; cmp i and n
        jnl     end_for           ; if not i <= n, quit

	mov	eax, [edx+1*ecx]  ; eax = array[i]
	call	print_char
	
	mov	eax, space
	call	print_string

        inc     ecx
        jmp     short for_loop

end_for:
	mov	ecx, [ebp+8]	; ecx = len of array
	sub	ecx, 1		; ecx = ecx -1
	mov	eax, [edx+1*ecx]  ; eax = array[ecx]
	call	print_char
	
	mov	eax, close
	call	print_string

        popa
        leave
        ret
