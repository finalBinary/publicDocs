flags01: driver.o flags01.o asm_io.o
	gcc -m32 -o flags01 -std=c99 -Wall asm_io.o driver.c flags01.o

driver.o: flags01.o
	gcc -m32 -c driver.c

flags01.o: flags01.asm asm_io.o
	nasm -f elf flags01.asm

asm_io.o:
	nasm -f elf -d ELF_TYPE asm_io.asm

clean:
	rm *.o flags01

