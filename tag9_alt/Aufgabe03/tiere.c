// #include date.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"
typedef enum {Hund, Katze} ART;

typedef struct tier {
	char rasse[100];
	char name[100];
	date geburtstag;
	ART art;
	struct tier * next;
} tier;


int read(tier *tiere, int anzahl);
int finde_art(char * art);
tier get_oldest(tier *tiere, int anzahl);
void add(tier * start, tier *toAdd);
void printTierList(tier * start);
void printTier(tier * t);
tier * createTier(char * rasse, char * name, int d, int m, int y, ART art);
void remove_oldest(tier ** start);
void freeList(tier **start);

int main(int argc, char **argv) {

	tier * start = NULL;

	tier *t1 = createTier("wuu", "foo", 10, 10, 2008, Hund);
	start = t1;

	tier * t2 = createTier("wuu1", "foo1", 11, 11, 2011, Hund);
	add(start, t2);

	tier * t3 = createTier("wuu2", "foo2", 12, 12, 1012, Hund);
	add(start, t3);

	tier *t4 = createTier("wuu", "foo", 10, 10, 2010, Hund);
	add(start, t4);

	tier *t5 = createTier("wuu", "foo", 10, 10, 2009, Hund);
	add(start, t5);


	printTierList(start);

	remove_oldest(&start);
	printf("\n---\n");
	printTierList(start);

	remove_oldest(&start);
	printf("\n---\n");
	printTierList(start);

	remove_oldest(&start);
	printf("\n---\n");
	printTierList(start);

	freeList(&start);
}

tier * createTier(char * rasse, char * name, int d, int m, int y, ART art) {
	tier * t = malloc(sizeof(tier));
	strcpy(t->rasse, rasse);
	strcpy(t->name, rasse);
	t->geburtstag.day = d;
	t->geburtstag.month = m;
	t->geburtstag.year = y;
	t->art = art;
	t->next = NULL;
	return t;
}

void add(tier * start, tier * toAdd) {
	tier * end = start;
	while(end->next != NULL){
		printf("!\n");
		end = end->next;
	}

	end->next = toAdd;
}

void printTierList(tier * start) {
	tier * temp = start;
	printTier(temp);
	while(temp->next != NULL){
		printf("\t|\n");
		printf("\tV\n");
		temp = temp->next;
		printTier(temp);
	}
}

void printTier(tier * t) {
	printf("%s, %s, ", t->rasse, t->name);
	print_date(t->geburtstag);
	if(t->art == Hund){
		printf(", Hund\n");
	} else {
		printf(", Katze\n");
	}
}

int read(tier *tiere, int anzahl) {
	char rasse[100];
	char name[100];
	int day;
	int month;
	int year;
	char art[20];

	int i = 0;
	while((scanf("%s %s %i %i %i %s", rasse, name, &day, &month, &year, art) != EOF) && i < anzahl) {
		strcpy(tiere[i].rasse, rasse);
		strcpy(tiere[i].name, name);
		tiere[i].geburtstag.day = day;
		tiere[i].geburtstag.month = month;
		tiere[i].geburtstag.year = year;
		tiere[i].art = finde_art(art); 
		i++;
	}
	return i;
}

int finde_art(char * art) {
	if(strcmp(art, "Hund")){
		return Hund;
	} if(strcmp(art, "Katze")){
		return Katze;
	}
	return -1;
}

tier get_oldest(tier *tiere, int anzahl) {
	tier oldest = tiere[0];
	for(int i =1; i<anzahl; i++){
		if(is_before(oldest.geburtstag, tiere[i].geburtstag) == 1){
			oldest = tiere[i];
		}
	}
	return oldest;
}

void remove_oldest(tier ** start) {
	tier * temp = *start;
	tier * oldest = *start;
	tier * bevor = NULL;

	//find oldest
	while(temp->next != NULL){
		if(is_before((temp->next)->geburtstag, oldest->geburtstag) == -1){
			oldest = temp->next;
			bevor = temp;
		}
		temp = temp->next;
	}

	//if oldest ist start, move start and remove old start
	if(oldest == *start){
		temp = *start;
		*start = (*start)->next;
		free(temp);
		return;
	}

	//if oldest is last, remove and set next of preceeding to null
	if(oldest->next == NULL){
		bevor->next = NULL;
		free(oldest);
		return;
	}

	bevor->next = oldest->next;
	free(oldest);
}

void freeList(tier **start){
	tier * temp = *start;
	tier * ptr;

	while(temp != NULL && temp->next != NULL){
		ptr = temp->next;
		(*start)->next = ptr->next;
		temp = ptr->next;
		free(ptr);
	}

	free(*start);
}
