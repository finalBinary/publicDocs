#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

int power(int base, int exponent);

int main(int argc, char * argv[]){
	int biggestNr = 0;
	int smalestNr = 0;
	short n = 0;
	

	/* get option arguments */
	char arg;
	while( (arg = getopt(argc, argv, "mM")) != EOF ){
		switch(arg){
			case 'm':
				smalestNr = 1; break;
			case 'M':
				biggestNr = 1; break;
		}
	}
	argc -= optind; // skip read arguments
  	argv += optind;

	

	printf("Bytes needed for short: %d\n", sizeof(n));

	if(biggestNr){
		printf("Biggest number is: %d\n", power(2, (sizeof(n)*8 - 1) )-1);
	}

	if(smalestNr)
		printf("Samlest number is: %d\n", -1*power(2, (sizeof(n)*8 - 1) ));

	return 0;
}


/* calculate exponential: base^exponent */
int power(int base, int exponent){
	if(exponent == 0) return 1;

	int result = base;

	for(int i = 1; i < exponent; i++){
		result = result * base;
	}

	return result;
}

