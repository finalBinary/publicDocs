aufgabe: driver.o aufgabe.o asm_io.o
	gcc -m32 -o aufgabe -std=c99 -Wall asm_io.o driver.c aufgabe.o

driver.o: aufgabe.o
	gcc -m32 -c driver.c

aufgabe.o: aufgabe.asm asm_io.o
	nasm -f elf aufgabe.asm

asm_io.o:
	nasm -f elf -d ELF_TYPE asm_io.asm

clean:
	rm *.o aufgabe

