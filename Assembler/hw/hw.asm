section .data
	; initialized data is put in the data segment here
	msg db "Hello World", 0xa
	len equ $-msg

;sction .bss
	; uninitialized data is put in the bss segment

section .text
	global start

start:

	MOV RAX, 1
	MOV RDI, 1
	MOV RSI, msg
	MOV RDX, 12
	syscall

	MOV RAX, 60
	MOV RDI, 0
	syscall

