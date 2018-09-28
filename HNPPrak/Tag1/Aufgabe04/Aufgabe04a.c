#include <stdio.h>

int separable(int a){

	if(a % 3 == 0) return 1;
	return 0;
}

void intTranslator(int toCheck){
	if(toCheck == 1){
		printf("is");
	} else {
		printf("is not");
	}
}


int main(){
	int input = 0;

	printf("Please enter Number to Ckeck:\n");
	scanf("%d", &input);

	printf("The Number %d ", input);
	intTranslator(separable(input));
	printf(" seperable by Three.\n");

	return 0;
}
