#include <stdio.h>

void weekday2015(int day){
	int weekIndex = day % 7;

	switch(weekIndex){
		case 1: printf("Donnerstag\n"); break;
		case 2: printf("Freitag\n"); break;
		case 3: printf("Sammstag\n"); break;
		case 4: printf("Sonntag\n"); break;
		case 5: printf("Montag\n"); break;
		case 6: printf("Dienstag\n"); break;
		case 0: printf("Mittwoch\n"); break;
			
	}
}

int main(){
	int input = 0;

	printf("Enter number:\n");
	scanf("%d", &input);

	weekday2015(input);
}
