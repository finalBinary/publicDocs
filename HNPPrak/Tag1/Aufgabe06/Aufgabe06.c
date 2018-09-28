#include <stdio.h>

int oktal(int toConvert){
	int result = 0, powr = 1;

	while (toConvert != 0){
		result += (toConvert % 8) * powr;
		toConvert /= 8;
		powr *= 10;
	}

	return result;
}

int main(){
	int input = 0;

	printf("Enter Number:");
	scanf("%d", &input); 
	printf("%d\n",oktal(input));

	return 0;
}
