#include <stdio.h>

int main(){
	int result = 0;

	for (int i=1; i<=100; i++){
		result += i;
	}

	printf("Summe: %d\n", result);

	return 0;
}
