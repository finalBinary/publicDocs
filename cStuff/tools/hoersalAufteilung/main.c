#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>

void printSudents(char *id, char *subject, char *points, int *params);
void process_col(char * col, int *params);
void get_params(int argc, char * argv[], int * params);

int main(int argc, char * argv[]){

	/* check for minium arguments and correct quantity*/
	if(argc < 4 || argc % 2 != 0){
		printf("Min. 3 arguments: inputFile, ouputFile1, places\n");
		return 1;
	}

	/* open input file */
	FILE *in;
	if(strcmp(argv[1], "stdin") == 0){
		in = stdin;
	}
	else if (!(in = fopen(argv[1], "r"))) {
  		fprintf(stderr, "Cant open file.\n");
  		return 1;
	}

	/* get initial input file and places */
	int availablePlaces;
	FILE *out;
	if (!(out = fopen(argv[2], "w"))) {
  		fprintf(stderr, "Cant open file.\n");
  		return 1;
	}
	sscanf(argv[3], "%d", &availablePlaces);
	

	char line[80];
	int fileIndex = 2; // curent index of argv file name
	int distributed = 0; // ditributed numbers for current output file
	
	while(fscanf( in, "%79[^\n]\n", line) == 1){
		
		char * col = strtok(line, ",");

		/* if current hall is not full add student*/
		if(distributed < availablePlaces){
			fprintf(out, "%s\n", col);
			distributed ++;
		}
		/* if current hall is full and next output exists, open next output file*/
		else if (argc-4 >= fileIndex) {
			fileIndex+=2; // increment file counter
			if (!(out = fopen(argv[fileIndex], "w"))) {
  				fprintf(stderr, "Cant open file.\n");
  				return 1;
			}
			sscanf(argv[fileIndex+1], "%d", &availablePlaces); //set hall capacity
			distributed = 0; // reset current ditributed to zero
		}
	}

	return 0;
}