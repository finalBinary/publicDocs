
hello: driver.c hw.o
	gcc driver.c hw.o -o hello
	
hw: hw.o
	nasm -f elf64 hw.asm -o hw.o

hw.o: hw.asm
	nasm -f elf64 hw.asm -o hw.o
