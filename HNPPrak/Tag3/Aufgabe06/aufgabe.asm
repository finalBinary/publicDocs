%include "asm_io.inc"
;
; initialized data is put in the .data segment
;
segment .data
;
; These labels refer to strings used for output
;
s1 db "Geben Sie die erste Zahl ein: ", 0
s2 db "Geben Sie die zweite Zahl ein: ", 0
s3 db "Geben Sie die dritte Zahl ein: ", 0

s4 db "Die Checksumme ist: ", 0

;
; code is put in the .text segment
;
segment .text
    global asm_haupt 
asm_haupt:
    enter 0,0
    pusha
    
    
    ; read input
    mov eax, s1
    call print_string
    call read_int
    mov ebx, eax
    
		
	mov ecx, 8
		
	start_transform:
			
		cmp ebx, ecx ; if < 7 just print
		jb end_out
		
		
		mov eax, ebx ; move current nr to eax, to be able to devide
		cdq
		idiv ecx
		mov ebx, eax
		
		
		mov eax, edx ;print rest
		call print_int
	
		cmp ebx, ecx ; if resultm of devision > 7 continue to transform
		jae start_transform
	
	end_out:
		mov eax, ebx ; print last rest
		call print_int
		call print_nl
    
    
    
    popa
    mov eax, 0 
    leave
    ret
