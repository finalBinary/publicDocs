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
b	resd	2
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

	; read input
	mov	eax, s1
	call	print_string
	call	read_int
	mov	[b], eax

    	;calculate
	push	dword [b]	;push b on stack
	push	dword [a]	;push a on stack
    	;call	euklid_iter
    	call	euklid_rec
	add	esp, 8

	;print result
	call	print_int
	call	print_nl

	popa
	mov	eax, 42 
	leave
	ret

;============================================================

euklid_iter:
	enter 4, 0
	pusha	;freze registers

	mov 	eax, [ebp+8]
	mov	ebx, [ebp+12]

while:
	cmp	ebx, 0
	je	end_while
	
	xor	edx, edx	; zero edx
	div	ebx		; eax = edx:eax / ebx, edx = edx:eax % ebx 
	mov	eax, ebx 
	mov	ebx, edx
	jmp	while
	
end_while:
	mov	[ebp-4], eax ; store result in local variable

	popa	; restore initial registers
	mov	eax, [ebp-4] ; move result to eax
	
	leave
	ret

;============================================================

euklid_rec:
	enter 4, 0
	pusha	; freze registers

	mov 	eax, [ebp+8]
	mov	ebx, [ebp+12]

	cmp	ebx, 0
	je	return

	xor edx, edx	; zero edx
	div ebx		; eax = edx:eax / ebx, edx = edx:eax % ebx
	push edx	; push a % b un stack
	push ebx	; push b on stck
	call euklid_rec	; call function recursive with new parameters on stack
	add esp, 8	; clean up!

return:
	mov	[ebp-4], eax ; store result in local variable

	popa	; restore initial registers
	mov	eax, [ebp-4] ; move result to eax
	
	leave
	ret

