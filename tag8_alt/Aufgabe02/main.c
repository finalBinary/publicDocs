#include <stdio.h>
#include "date.h"

int main(int argc, char * argv[]){

	struct date firstDate;
	struct date secondDate;

	printf("Enter first Date:\n");
	scanf("%hu %hu %hu", &firstDate.day, &firstDate.month, &firstDate.year);

	printf("Enter second Date:\n");
	scanf("%hu %hu %hu", &secondDate.day, &secondDate.month, &secondDate.year);

	if(is_before(firstDate, secondDate) == 0){
		printf("The date: ");
		printDate(&firstDate);
		printf("is equal to: ");
		printDate(&secondDate);
	}
	else if(is_before(firstDate, secondDate) == -1){
		printf("The date: ");
		printDate(&firstDate);
		printf("is before: ");
		printDate(&secondDate);
	}
	else if(is_before(firstDate, secondDate) == 1){
		printf("The date: ");
		printDate(&firstDate);
		printf("is after: ");
		printDate(&secondDate);
	}

	return 0;
}