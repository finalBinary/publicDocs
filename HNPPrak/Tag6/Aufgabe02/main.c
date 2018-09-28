#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

// testing: gcc main.c taschenrechner2_tests.c -o _tests -Wall -std=c99 -g -fprofile-arcs -ftest-coverage -pthread -lcheck -lrt -lm -lsubunit

int calc(int x, int y, int interval, int exponent);
int mult_interval(int x, int y, int interval);
int divide(int nr, int divisor);
void help_message();

int main(int argc, char * argv[]){
	int x;
	int y;
	int interval = 1;
	int divisor = 1;

	// check for minimum nr. of arguments
	if(argc < 3){
		printf("Min. 2 arguments: x, y\n");
		return 1;
	}

	// get option arguments
	char arg;
	while( (arg = getopt(argc, argv, "hm:d:")) != EOF ){
		switch(arg){
			case 'm':
				sscanf (optarg,"%d",&interval); break;
			case 'd':
				sscanf (optarg,"%d",&divisor); break;
			case 'h':
				help_message(); break;	
		}
	}
	argc -= optind; // skip read arguments
  	argv += optind;

	// get int arguments
	sscanf (argv[0],"%d",&x);
	sscanf (argv[1],"%d",&y);

	printf("%d\n", calc(x, y, interval, divisor));

	return 0;
}


int calc(int x, int y, int interval, int divisor){
	int mult = mult_interval(x, y, interval);
	return divide(mult, divisor);
}

/* mlt numbers between x and y for a given interval*/
int mult_interval(int x, int y, int interval){
	int mult = 1;

	for(int i = x; i <= y; i+= interval){
		mult *= i;
	}

	return mult;
}

/* calculate exponential: base^exponent */
int divide(int nr, int divisor){
	if(divisor == 0) return 1;

	return nr / divisor;
}

void help_message(){
	printf("Options:\n\
\t-a i: sets interval of i\n\
\t-p e: sets exponent to e\n\
Arguments:\n\
\tfirst: start of interval\n\
\tsecond: end of interval\n");
}
