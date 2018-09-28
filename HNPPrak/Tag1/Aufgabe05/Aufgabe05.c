#include <stdio.h>

void printArray(int array[]){
	for(int i = 0; i < 5; i++) {
		printf("%d, ", array[i]);
	} 
}

int * calculateChange(int amount){
	int change[5] = {0};
	int possibleValues[5] = {50, 20, 10, 2, 1};

	for(int i = 0; i < 5; i++){
		change[i] = amount/possibleValues[i];

		if(amount == 0) break;
		amount = amount % possibleValues[i];
	}

	printArray(change);
	printf("\n");

	return 0;
}


int main(){
	int input = 0;

	printf("Please enter Amount to change:\n");

	scanf("%d", &input);

	printf("Your Change of 50, 20, 10, 2 an 1 Cent is distributed like: ");
	calculateChange(input);

	return 0;
}
