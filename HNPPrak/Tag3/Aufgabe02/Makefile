aufgabe01: driver.o aufgabe01.o asm_io.o
	gcc -m32 -o aufgabe01 -std=c99 -Wall asm_io.o driver.c aufgabe01.o

driver.o: aufgabe01.o
	gcc -m32 -c driver.c

aufgabe01.o: aufgabe01.asm asm_io.o
	nasm -f elf aufgabe01.asm

asm_io.o:
	nasm -f elf -d ELF_TYPE asm_io.asm

clean:
	rm *.o aufgabe01

