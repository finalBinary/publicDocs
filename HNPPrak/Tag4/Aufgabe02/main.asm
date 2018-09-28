%include "asm_io.inc"

;*******************************************************
; initialized data is put in the .data segment
;
segment .data

s1 db	"Geben Sie eine Zahl ein: ", 0
s2 db	"Das ist die Zahl, die Sie eingegeben haben: ", 0
;*******************************************************


;*******************************************************
; reserve memory for variables
;
segment .bss
a	resd	1
;*******************************************************


;*******************************************************
; code is put in the .text segment
;
segment .text
	global asm_main 
asm_main:
	enter 0,0
	pusha


	; read input
	mov 	eax, s1
	call 	print_string
	call 	read_int
	mov 	[a], eax

    	;calculate
	push	dword [a]	;push a on stack
    call	fak_iter
    ;call	fak_rec
	add	esp, 4

	;print result
	call	print_int
	call	print_nl

	popa
	mov	eax, 42 
	leave
	ret

;============================================================

fak_iter:
	enter 4, 0
	pusha	;freze registers

	mov 	eax, [ebp+8] ; get n from stack
	mov	ebx, eax ; x = n

while:
	cmp		eax, 1
	je		end_while
	
	sub eax, 1		; n = n - 1
	push eax		; push a on stck to freze
	
	
	xor		edx, edx	; zero edx
	mul		ebx		; x = x * n
	mov ebx, eax
	
	pop eax ; retreive a from stack
	jmp		while
	
end_while:
	mov	[ebp-4], ebx ; store result in local variable

	popa	; restore initial registers
	mov	eax, [ebp-4] ; move result to eax
	
	leave
	ret

;============================================================

fak_rec:
	enter 4, 0
	pusha	; freze registers

	mov 	eax, [ebp+8]

	cmp	eax, 1
	jne	else

return:
	mov	[ebp-4], dword 1 ; store result in local variable
	jmp end
	
else
	mov 	ebx, eax
	sub 	ebx, 1 ; n - 1
	push 	ebx	; push n - 1 on stack
	
	mov		ecx, eax ; store n in ecx
	
	call fak_rec	; call function recursive with new parameters on stack
	
	mul 	ecx		; eax * ecx = fak_rec(n-1) * n
	mov		[ebp-4], eax ; store result in local variable
	
	add 	esp, 4	; clean up!
	
end:

	popa	; restore initial registers
	mov	eax, [ebp-4] ; move result to eax
	
	leave
	ret
	

