#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include "supermarkt.h"

void process_col(char * col, int *params);
void get_params(int argc, char * argv[], int * params);
void printLine(char *name, char *quantity, char *category, char *durability, int *params);
void printQuanitityChecked(char *name, char *quantity, char *category, char *durability, int quantityToCheck);

int main(int argc, char * argv[]){
	
	char line[80];


	int params[] = {400, -1, -1, 0}; // minDurability, minFruitDurability, minAnzahl, invert

	get_params(argc, argv, params);

	while(fgets(line, 80, stdin) != NULL){
	
		line[strcspn(line, "\n")] = '\0'; // remove trailing newlinechar
		
		char * col = strtok(line, "\t");

		process_col(col, params);
	}

	return 0;
}

void process_col(char * col, int * params){
	int index = 0;
	char row[80][81] = {{"\0"}};

	while(col != NULL) {
		strcpy( (row[index]), col);
		col = strtok(NULL, "\t");
		index++;
	}

	printLine(row[0], row[1], row[2], row[3], params);
}

void printLine(char *name, char *quantity, char *category, char *durability, int *params){
	//int currentDurability = atoi(durability);

	/*if(strcmp("Obst", category) == 0){
		if(params[1] > -1 && currentDurability >= params[1]){
			printQuanitityChecked(name, quantity, category, durability, params[2]);
			return;
		} else if(currentDurability >= params[0]){
			printQuanitityChecked(name, quantity, category, durability, params[2]);
			return;
		}
	}

	else if(currentDurability >= params[0]){
			printQuanitityChecked(name, quantity, category, durability, params[2]);
			return;
	}
	else if(params[3] > 0){
		printQuanitityChecked(name, quantity, category, durability, params[2]);
		return;
	}*/
	
	//ausgeben(int haltbarkeit_allgemein, int haltbarkeit_obst, int mindestanzahl, int umkehren, int anzahl, char *kategorie, int resthaltbarkeit);
	
	int haltbarkeit_allgemein = params[0];
	int haltbarkeit_obst = params[1];
	int mindestanzahl = params[2];
	int umkehren = params[3];
	int anzahl = atoi(quantity);
	int resthaltbarkeit = atoi(durability);
	
	if(ausgeben(haltbarkeit_allgemein, haltbarkeit_obst, mindestanzahl, umkehren, anzahl, category, resthaltbarkeit) == 1){
		printf("%s\n", name);
	}
}


int individuelle_haltbarkeit(int haltbarkeit_allgemein, int haltbarkeit_obst, char *kategorie){
	
	if(ist_obst(kategorie) == 1){
		return haltbarkeit_obst;
	}
	return haltbarkeit_allgemein;
}

int ist_obst(char *kategorie){
	if(strcmp("Obst", kategorie) == 0) return 1;
	return 0;
}

int ist_oft_genug_vorhanden(int mindestanzahl, int anzahl){
	if(mindestanzahl <= anzahl) return 1;
	return 0;
}


void get_params(int argc, char * argv[], int * params){
	/*if(argc < 2){
		printf("Min. 2 arguments\n");
		return;
	}*/

	/* get option arguments */
	char arg;
	while( (arg = getopt(argc, argv, "o:a:u")) != EOF ){
		switch(arg){
			case 'o':
				sscanf (optarg,"%d", &params[1]); break;
			case 'a':
				sscanf (optarg,"%d", &params[2]); break;
			case 'u':
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


// extra ====================================================================================

int ausgeben(int haltbarkeit_allgemein, int haltbarkeit_obst, int mindestanzahl, int umkehren,
             int anzahl, char *kategorie, int resthaltbarkeit){
				 
	if(umkehren == 0){
		if(resthaltbarkeit >= individuelle_haltbarkeit(haltbarkeit_allgemein, haltbarkeit_obst, kategorie) && ist_oft_genug_vorhanden(mindestanzahl, anzahl) == 1) {
				return 1;
		}
		return 0;
	}
	
	if(umkehren == 1){
		if(resthaltbarkeit <= individuelle_haltbarkeit(haltbarkeit_allgemein, haltbarkeit_obst, kategorie) && ist_oft_genug_vorhanden(mindestanzahl, anzahl) == 1) {
				return 1;
		}
		return 0;
	}
		
	return 0;		 
}

void printQuanitityChecked(char *name, char *quantity, char *category, char *durability, int quantityToCheck){
	int currentQuantity = atoi(quantity);
	if( quantityToCheck == -1 || currentQuantity > quantityToCheck){
		printf("%s\n", name);
	}
}
