#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>

void printSudents(char *id, char *subject, char *points, int *params);
void process_col(char * col, int *params);
void get_params(int argc, char * argv[], int * params);

int main(int argc, char * argv[]){

	char line[80];

	FILE *in;
	if (!(in = fopen("student.csv", "r"))) {
  		fprintf(stderr, "Cant open file.\n");
  		return 1;
	}

	int params[] = {100, 50, 50, 1};

	get_params(argc, argv, params);

	while(fscanf( in, "%79[^\n]\n", line) == 1){
		
		char * col = strtok(line, ",");

		process_col(col, params);
	}

	return 0;
}

void get_params(int argc, char * argv[], int * params){
	/* check for minimum nr. of arguments */
	if(argc < 2){
		//printf("Min. 2 arguments: x, y\n");
		return;
	}

	/* get option arguments */
	char arg;
	while( (arg = getopt(argc, argv, "i:n:v")) != EOF ){
		switch(arg){
			case 'i':
				sscanf (optarg,"%d", &params[1]); break;
			case 'n':
				sscanf (optarg,"%d", &params[2]); break;
			case 'v':
				params[3] = 0; break;	
		}
	}
	argc -= optind; // skip read arguments
  	argv += optind;

	/* get int arguments */
	if(argc > 0){
		sscanf (argv[0],"%d", &params[0]);
	}
}

void process_col(char * col, int *params){
	int index = 0;
	char row[80][81] = {{"\0"}};

	while(col != NULL) {
		strcpy( (row[index]), col);
		col = strtok(NULL, ",");
		index++;
	}

	printSudents(row[0], row[1], row[2], params);
}

void printSudents(char *id, char *subject, char *points, int *params){
	float percent = (atoi(points) * 100.0) / params[0];

	if(strcmp("Informarik", subject) == 0){
		if(percent >= params[1]){
			printf("%s, %s, %s\n", id, subject, points);
		}
	}
	else if(strcmp("Mathe", subject) == 0){
		if(percent >= params[2]){
			printf("%s, %s, %s\n", id, subject, points);
		}
	}
	else if(percent >= params[2] && params[3] != 0){
		printf("%s, %s, %s\n", id, subject, points);
	}
}