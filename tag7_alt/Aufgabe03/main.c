#include <stdio.h>

int main(int argc, char * argv[]){

	//declare 1 as int:
	//Big: 00 00 00 01
	//Little: 01 00 00 00
	unsigned int i = 1;

	//cast int to char (on byte)
	//only first byte is transfered
  	char c = (char) i;

  	//check content of char to decide endianness
  	if (c)    
       printf("Little-Endian\n");
	else
       printf("Big-Endian\n");

	return 0;
}