#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dungeon.h"

/* Wir geben Ihnen die main sowie eine Funktion zur Befehlsverarbeitung bereits
 * vor und empfehlen, dass Sie diese nicht ändern. Weitere Informationen zu
 * bereits vorhandenen Funktionen finden Sie in dungeon.h.
 */
 
int main(int argc, char **argv){
	spielstand st;
	st.inventar = NULL;
	int exit = 0;
	if((exit = lade_spielstand(&st)) == 0){
		if( argc == 2 ) exit = befehlsverarbeitung(argv[0], argv[1], &st);
		else if (argc == 1) exit = befehlsverarbeitung(argv[0], NULL, &st);
		else exit = 2;
	}
	if (exit == 0) exit = speichere_spielstand(st);
	
	liste_freigeben(st.inventar);
	return exit;
}


int befehlsverarbeitung(char *befehl, char *gegenstand, spielstand *st){
	int exit = 0;
	if(strcmp(befehl, "./nimm") == 0){
		if (gegenstand == NULL){
			exit = 2;
			fprintf(stderr, "Was moechtest Du nehmen?\n");
		}
		else nimm(gegenstand, st);
	} else if (strcmp(befehl, "./guck") == 0) exit = guck(st);
	else if (strcmp(befehl, "./n") == 0) exit = gehe(NORD, st);
	else if (strcmp(befehl, "./s") == 0) exit = gehe(SUED, st);
	else if (strcmp(befehl, "./w") == 0) exit = gehe(WEST, st);
	else if (strcmp(befehl, "./o") == 0) exit = gehe(OST, st);
	else if (strcmp(befehl, "./inv") == 0) inv(st->inventar);
	else{
		exit = 2;
		fprintf(stderr, "Der Befehl \'%s\' ist nicht bekannt.\n", befehl);
	}
	return exit;
}

/* Implementieren Sie die folgenden Funktionen */



int lade_spielstand(spielstand *st){
	// TODO
	
	FILE * stFile;
	
	if (!(stFile = fopen("spielstand", "r"))) {
  		fprintf(stderr, "Cant open file.\n");
  		return 1;
	}
	
	char raum[256];
	fscanf( stFile, "%s", raum);
	
	liste * items = NULL;
	char item[256];
	while(fscanf( stFile, "%s", item) == 1){
		if(items == NULL){
			items = createList(item);
		} else {
			addToList(items, createList(item));
		}
	}
	
	strcpy(st->aktueller_raum, raum);
	st->inventar = items;
	
	//printList(items);
	fclose(stFile);
	
	return 0;
}

int speichere_spielstand(spielstand st){
	// TODO
	printf("Saving\n");
	
	
	FILE *out;
	if (!(out = fopen("spielstand", "w"))) {
  		fprintf(stderr, "Cant open file.\n");
  		return 1;
	}
	
	
	//Save Raum
	fprintf(out, "%s\n", st.aktueller_raum);
	
	//Save Inventar
	liste * temp = st.inventar;
	if(temp != NULL){
		while(temp != NULL){
			fprintf(out, "%s ", temp->item);
			temp = temp->next;
		}
	}
	
	fclose(out);
	
	return 0;
}

raum * readRoom(char * roomName){
	
	//initialize
	raum * room = malloc(sizeof(raum));
	room->ausgang_norden = NULL;
	room->ausgang_sueden = NULL;
	room->ausgang_westen = NULL;
	room->ausgang_osten = NULL;
	room->gegenstaende = NULL;

	
	FILE * roomFile;
	
	if (!(roomFile = fopen(roomName, "r"))) {
  		fprintf(stderr, "Cant open file.\n");
  		return NULL;
	}
	
	//parse description
	fgets(room->beschreibung, 1024, roomFile);

		
	//parse rooms
	int index = 0;
	ausgang * temp = NULL;
	char name[256], item[256], desc[1024], line[1536];
	while(index < 4){

		fgets(line, 1536, roomFile);
		

		if(sscanf(line, "%s\t%s\t%s", name, item, desc) == 3){
			temp = malloc(sizeof(ausgang));
			
			strcpy(temp->name, name);
			strcpy(temp->item, item);
			strcpy(temp->beschreibung, desc);
		} else if(sscanf(line, "%s", name) == 1){
			temp = malloc(sizeof(ausgang));
			
			strcpy(temp->name, name);
			strcpy(temp->item, "");
			strcpy(temp->beschreibung, "");
		}
		
		
		switch(index){
			case 0: room->ausgang_norden = temp; break;
			case 1: room->ausgang_sueden = temp; break;
			case 2: room->ausgang_westen = temp; break;
			case 3: room->ausgang_osten = temp; break;
		}
				
		index++;
	}
	
	//parse items
	liste * items = NULL;
	char singleItem[256];
	while(fscanf(roomFile, "%s", singleItem) == 1){
		if(items == NULL){
			items = createList(singleItem);
		} else {
			addToList(items, createList(singleItem));
		}
	}
	room->gegenstaende = items;
	
	//close file
	fclose(roomFile);
	
	return room;
}

void printAusgang(ausgang * exit){
	if(exit != NULL){
		printf("\t%s\n", exit->name);
		//printf("\t%s\n", exit->item);
	}
}

void printRoom(raum * room){
	printf("%s", room->beschreibung);
	
	printf(GUCK_AUSGAENGE);
	printf(GUCK_NORD, room->ausgang_norden->name);
	printf(GUCK_SUED, room->ausgang_sueden->name);
	printf(GUCK_WEST, room->ausgang_westen->name);
	printf(GUCK_OST, room->ausgang_osten->name);

	
	/*printAusgang(room->ausgang_norden);
	printf("Ausgang Sueden: ");
	printAusgang(room->ausgang_sueden);
	printf("Ausgang Westen: ");
	printAusgang(room->ausgang_westen);
	printf("Ausgang Osten: ");
	printAusgang(room->ausgang_osten);*/
	
	printf(GUCK_GEGENSTAND);
	printList(room->gegenstaende);
}



void freeRaum(raum * room){
	free(room->ausgang_norden);
	free(room->ausgang_sueden);
	free(room->ausgang_westen);
	free(room->ausgang_osten);
	
	if(room->gegenstaende != NULL){
		liste_freigeben(room->gegenstaende);
	}
	
	free(room);
}

void goInRoom(ausgang * exit, liste *items, spielstand *st){
	printf("going in room\n");
	if(exit->item == NULL || isInList(st->inventar, exit->item) == 0){
		printf("%s\n", exit->name);
		strcpy(st->aktueller_raum, exit->name);
		
		st->inventar = items;
	} else {
		printf("you need following item to enter this room: %s\n", exit->item);
	}
}

int gehe(richtung r, spielstand *st){
	// TODO
	
	
	raum * currentRoom = readRoom(st->aktueller_raum);
	
	//printf("%s\n", currentRoom->beschreibung);
	//printf("%s\n", currentRoom->ausgang_norden->name);

	
	switch(r){
		case NORD: printf("Nord\n"); goInRoom(currentRoom->ausgang_norden, currentRoom->gegenstaende, st); break;
		case SUED: printf("SUED\n"); goInRoom(currentRoom->ausgang_sueden, currentRoom->gegenstaende,st); break;
		case WEST: printf("WEST\n"); goInRoom(currentRoom->ausgang_westen, currentRoom->gegenstaende,st); break;
		case OST: printf("OST\n"); goInRoom(currentRoom->ausgang_osten, currentRoom->gegenstaende,st); break;
	}
	
	freeRaum(currentRoom);
	
	return 0;
}

void inv(liste *start){
	// TODO
	
	if(start == NULL){
		printf(INVENTAR_LEER);
	} else {
		printf(INVENTAR_VOLL);
		printList(start);
	}
}

int nimm(char *gegenstand, spielstand *st){
	// TODO
	
	if(st->inventar == NULL){
		st->inventar = createList(gegenstand);
	} else if(isInList(st->inventar, gegenstand)){
		addToList(st->inventar, createList(gegenstand));
	}
	
	
	return 0;
}

int guck(spielstand *st){
	// TODO
	
	raum * currentRoom = readRoom(st->aktueller_raum);
	
	printf(MEIN_STANDORT, st->aktueller_raum);
	printRoom(currentRoom);
	
	freeRaum(currentRoom);

	return 0;
}

void liste_freigeben(liste *start){
	//TODO
	if(start != NULL){
	liste * temp = start->next;

	while(temp != NULL){
		free(start);
		start = temp;
		temp = start->next;
	}

	free(start);
	}
}


void print_ausgang(int i, char* ort){
	switch (i){
		case 1: printf(GUCK_NORD, ort); break; 
		case 2: printf(GUCK_SUED, ort); break; 
		case 3: printf(GUCK_WEST, ort); break; 
		case 4: printf(GUCK_OST, ort); break; 
	}
}

void richtung_to_string(richtung r, char* r_string){
	switch(r){
		case NORD: strcpy(r_string, "Norden"); break;
		case SUED: strcpy(r_string, "Süden"); break;
		case WEST: strcpy(r_string, "Westen"); break;
		case OST: strcpy(r_string, "Osten");
	}
}


/*
 * Eigene Funktionen
 */

liste * createList(char * item) {
	liste * l = malloc(sizeof(liste));
	strcpy(l->item, item);
	l->next = NULL;
	return l;
}

void addToList(liste * start, liste * toAdd) {
	liste * end = start;
	while(end->next != NULL){
		end = end->next;
	}

	end->next = toAdd;
}

void printList(liste * start) {
	if(start != NULL){
		liste * temp = start;
		printf("%s", temp->item);
		while(temp->next != NULL){
			printf(" -> ");
			temp = temp->next;
			printf("%s", temp->item);
		}
		printf("\n");
	}
}

int isInList(liste * start, char * itemToCheck) {
	if(start != NULL){
		liste * temp = start;
		while(temp->next != NULL){
			if(strcmp(temp->item, itemToCheck)){
				return 0;
			}
			temp = temp->next;
		}
	}
	return 1;
}
