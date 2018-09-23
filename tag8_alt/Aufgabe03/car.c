#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "car.h"

void printCar(struct car * ptr){
	printf("Brand: %s\n", ptr->brand);
	printf("Model: %s\n", ptr->model);
	printDate(&(ptr->constYear));
	printf("Original: %d\n", ptr->org);
};

struct car * readCar(){
	static struct car *carPtr;
	carPtr = malloc(sizeof(struct car));
	//char br[30] = {'a'};
	//strcpy(carPtr->brand, br);
	printf("Brand: \n");
    fgets(carPtr->brand, MAX_LEN, stdin);

    printf("Model: \n");
    fgets(carPtr->model, MAX_LEN, stdin);

    printf("Date: \n");
    char dateLine[MAX_LEN];
    fgets(dateLine, MAX_LEN, stdin);
    carPtr->constYear = *(parseDate(dateLine));

    printf("Org: ");
    int orgVal;
    scanf("%d", &orgVal);
    carPtr->org = orgVal;


    return carPtr;
}

struct car * readCarLine(char * line){
	static struct car *carPtr;
	carPtr = malloc(sizeof(struct car));

	//char * col = strtok(line, ",");
	//carPtr->brand = malloc(sizeof(col));
	//printf("tok: br: %s\n", col);
	//char bar[30];
	//strcpy( bar, strtok(line, ","));
	strcpy( (carPtr->brand), strtok(line, ","));

	//col = strtok(NULL, ",");

	//printf("tok: nod: %s\n", col);
	//strcpy( bar, strtok(NULL, ","));
	//char * bar2 = "123";
	//carPtr->model = bar2;
	strcpy( (carPtr->model), strtok(NULL, ","));
	//char * col3 = strtok(NULL, ",");

	//printf("tok: date: %s\n", col3);
	//strtok(NULL, ",");
	char * dateLine = strtok(NULL, ",");
	char * tmp = malloc(sizeof(dateLine));
	strcpy(tmp, dateLine);
	//carPtr->constYear = *(parseDate(strtok(NULL, ",")));
	//carPtr->constYear = *(parseDate(tmp));

	//col = strtok(NULL, ",");

	//char * o = strtok(NULL, ",");
	//printf("##: %s\n", strtok(NULL, ","));
	carPtr->org = atoi(strtok(NULL, ","));

	carPtr->constYear = *(parseDate(tmp));

    return carPtr;
}