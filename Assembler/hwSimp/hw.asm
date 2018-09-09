section .data
	msg db "Hello World", 0xa
	len equ $-msg

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

