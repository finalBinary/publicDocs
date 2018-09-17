#include <stdio.h>
#include <string.h>

int main(){
	float breitengrad;
	float laengengrad;
	char info[80];

	int begonnen = 0;

	puts("data=[");
	while(scanf("%f,%f,%79[^\n]", &breitengrad, &laengengrad, info) == 3){
		if(begonnen){
			printf(",\n");
		}
		else {
			begonnen = 1;
		}
		printf("{latidude: %f, longitude %f, info: '%s'}", laengengrad, breitengrad, info);
	}
	puts("\n]");

	return 0;
}