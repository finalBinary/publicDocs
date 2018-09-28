
#include <stdio.h>

void readNumber(int* nr);
void readChar(char* op);
int calc(int a, int b, char operator);

int main(){
	
	int a = 0;
	int b = 0;
	char operator;

	
	readNumber(&a);
	readChar(&operator);
	readNumber(&b);
	
	printf("result: %d\n", calc(a, b, operator));
	
	return 0;
}
