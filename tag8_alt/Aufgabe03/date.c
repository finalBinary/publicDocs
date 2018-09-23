#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"


void printDate(struct date * ptr){
	printf("%hd:%hd:%hd\n", ptr->day, ptr->month, ptr->year);
}

int is_before(struct date a, struct date b){
	if(a.day == b.day && a.month == b.month && a.year == b.year){
		return 0;
	}

	if( a.year < b.year
		|| (a.year == b.year && a.month < b.month)
		|| (a.year == b.year && a.month == b.month && a.day < b.day) ) {
		return -1;
	}


	return 1;	
}

struct date * readDate(){
	static struct date *datePtr;
	datePtr = malloc(sizeof(struct date));

	printf("Day: ");
    do {scanf("%hd",&datePtr->day);} while(getchar()!= '\n');

	printf("Month: ");
    do {scanf("%hd",&datePtr->month);} while(getchar()!= '\n');

	printf("Year: ");
    do {scanf("%hd",&datePtr->year);} while(getchar()!= '\n');
    

    return datePtr;
}

struct date * readDateLine(){
	static struct date *datePtr;
	datePtr = malloc(sizeof(struct date));

	char dateLine[8];
	do {scanf("%s", dateLine);} while(getchar()!= '\n');

	return datePtr;
}

struct date * parseDate(char * dateStr){
	static struct date *datePtr;
	datePtr = malloc(sizeof(struct date));
	//char * tmp = malloc(sizeof(dateStr));
	//strcpy(tmp, dateStr); 
	char * dateParts = strtok(dateStr, ":");
	//char foo = (char) dateParts[0];
	datePtr->day = atoi(dateParts);
	dateParts = strtok(NULL, ":");
	datePtr->month = atoi(dateParts);
	dateParts = strtok(NULL, ":");
	datePtr->year = atoi(dateParts);
	//strcpy( datePtr->day, dateParts);

	return datePtr;
}