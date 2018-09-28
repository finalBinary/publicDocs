#include <stdio.h>

void readValues(float* arrayPtr, int len);
void printArray(float* arrayPtr, int len);

int main(){
	float data[9] = {0};
	
	readValues(data, 9);

	printArray(data, 9);
	
	return 0;
}

void readValues(float* arrayPtr, int len){
	for(int i = 0; i<len; i++){
		printf("Enter Nr.: ");
		scanf("%f", arrayPtr + i);
	}
}

void printArray(float* arrayPtr, int len){
	printf("[");
	for(int i = 0; i<len-1; i++){
		printf("%f, ", *(arrayPtr+i));
	}
	printf("%f]\n", *(arrayPtr+(len-1)));
}


