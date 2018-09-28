execName = start
asmFileName = stack03

$(execName): driver.o $(asmFileName).o asm_io.o
	gcc -m32 -o $(execName) -std=c99 -Wall asm_io.o driver.c $(asmFileName).o

driver.o: $(asmFileName).o
	gcc -m32 -c driver.c

$(asmFileName).o: $(asmFileName).asm asm_io.o
	nasm -f elf $(asmFileName).asm

asm_io.o:
	nasm -f elf -d ELF_TYPE asm_io.asm

clean:
	rm *.o $(execName)

