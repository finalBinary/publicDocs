#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "car.h"
//#include "date.h"


int main(int argc, char * argv[]){
	//char chPtr[120];
	//unsigned short temp;
	//struct date * foo;

	//char bar[] = "10:12:1990";
	//foo = parseDate(bar);

	//printDate(foo);
	//struct car * foo = readCar();

	char bar[] = "ABC,DEF,10:10:2010,1";
	struct car * foo = readCarLine(bar);

	/*printf("\n###\n\n");
	printf("Brand: %s", foo->brand);*/

	printCar(foo);

	//struct car survey;
	//free(foo->brand);
	free(foo);

	return 0;
}