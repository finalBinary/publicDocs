#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

int calc(int x, int y, int interval, int exponent);
int sum_interval(int x, int y, int interval);
int power(int base, int exponent);
void help_message();

int main(int argc, char * argv[]){
	int x;
	int y;
	int interval = 1;
	int exponent = 1;

	/* check for minimum nr. of arguments */
	if(argc < 3){
		printf("Min. 2 arguments: x, y\n");
		return 1;
	}

	/* get option arguments */
	char arg;
	while( (arg = getopt(argc, argv, "ha:p:")) != EOF ){
		switch(arg){
			case 'a':
				sscanf (optarg,"%d",&interval); break;
			case 'p':
				sscanf (optarg,"%d",&exponent); break;
			case 'h':
				help_message(); break;	
		}
	}
	argc -= optind; // skip read arguments
  	argv += optind;

	/* get int arguments */
	sscanf (argv[0],"%d",&x);
	sscanf (argv[1],"%d",&y);

	printf("%d\n", calc(x, y, interval, exponent));

	return 0;
}


int calc(int x, int y, int interval, int exponent){
	int sum = sum_interval(x, y, interval);
	return power (sum, exponent);
}

/* sum numbers between x and y for a given interval*/
int sum_interval(int x, int y, int interval){
	int sum = 0;

	for(int i = x; i < y; i+= interval){
		sum += i;
	}

	return sum;
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

void help_message(){
	printf("Options:\n\
\t-a i: sets interval of i\n\
\t-p e: sets exponent to e\n\
Arguments:\n\
\tfirst: start of interval\n\
\tsecond: end of interval\n");
}