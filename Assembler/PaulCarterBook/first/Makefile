first: driver.o first.o asm_io.o
	gcc -m32 -o first -std=c99 -Wall asm_io.o driver.c first.o

driver.o: first.o
	gcc -m32 -c driver.c

first.o: first.asm asm_io.o
	nasm -f elf first.asm
Sprünge
asm_io.o:
	nasm -f elf -d ELF_TYPE asm_io.asm

clean:
	rm *.o first

