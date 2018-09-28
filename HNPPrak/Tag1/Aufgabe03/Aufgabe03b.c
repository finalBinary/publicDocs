#include <stdio.h>

int main(){
	int result = 0;

	for (int i = 0; i <= 100; i += 2){
		result += i;
	}

	printf("Summe: %d\n", result);

	return 0;
}
