#include <stdio.h>
#include "date.h"

void print_date(date dt){
	printf("%hd:%hd:%hd", dt.day, dt.month, dt.year);
}

int is_before(date a, date b){
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
