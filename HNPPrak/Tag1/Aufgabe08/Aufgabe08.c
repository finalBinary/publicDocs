#include <stdio.h>

int main(){
	int a = 10;
	float b = 1.;
	
	int * aPtr = &a;
	float * bPtr = &b;

	int * cPtr;


	//Die Ausgaben sind wie erwartet identisch
	printf("a = %u\n", &a);
	printf("b = %u\n", &b);
	
	printf("aPtr = %u\n", aPtr);
	printf("bPtr = %u\n", bPtr);

	printf("cPtr = %u\n", cPtr);


	*aPtr = 20;
	*bPtr = 2.;
	printf("a = %d\n", a);
	printf("b = %f\n", b);

	a = 30;
	b = 3.;
	printf("a = %d\n", *aPtr);
	printf("b = %f\n", *bPtr);
	return 0;
}
