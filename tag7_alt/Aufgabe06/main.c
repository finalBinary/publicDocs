#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <math.h>

void foo();

int main(int argc, char * argv[]){

	/* check for minium arguments and correct quantity*/
	if(argc < 2){
		printf("Please input a number\n");
		return 1;
	}

	long long inputLL = atoll(argv[1]);
	short inputS = (short) inputLL;
	long inputL = (long) inputLL;
	double inputD = (double) inputLL;

	printf("short: %hd\n", inputS);
	printf("long: %ld\n", inputL);
	printf("double: %f\n", inputD);

	//int foo = 0;
	foo();
	//int foo = 0;


	return 0;
}

void foo(){

}
