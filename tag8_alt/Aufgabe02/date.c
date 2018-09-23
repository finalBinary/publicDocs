#include <stdio.h>
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