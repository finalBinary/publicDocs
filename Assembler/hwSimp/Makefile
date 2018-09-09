hw: hw.o
	ld -o hw hw.o -e start -m elf_x86_64

hw.o: hw.asm
	nasm -f elf64 hw.asm -o hw.o
