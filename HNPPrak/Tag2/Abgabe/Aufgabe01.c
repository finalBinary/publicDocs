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

void readNumber(int* nr){
	printf("Please Enter Number:\n");
	scanf("%d", nr);
}

void readChar(char* op){
	printf("Please Enter Operator:\n");
	scanf("%s", op);
}

int calc(int a, int b, char operator){
	
	switch(operator){
		case '+': return a + b; break;
		case '-': return a - b; break;
		case '*': return a * b; break;
		case '/': return a/b; break;
	}
	
	return 0;
}
