#include <stdio.h>

void swap(int *a, int *b);

int main(){
	int a;
	int b;
	
	printf("Enter Numbers:\n");
	
	scanf("%d", &a);
	scanf("%d", &b);
	
	printf("a = %d; b = %d\n", a, b);
	
	swap(&a, &b);
	
	printf("a = %d; b = %d\n", a, b);
	
	
	return 0;
}


void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
