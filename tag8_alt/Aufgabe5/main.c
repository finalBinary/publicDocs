#include <stdio.h>
#include <string.h>

#include "form.h"

int main(int argc, char * argv[]){
	char chPtr[120];
	unsigned short temp;

	struct form survey;


	printf("Welches Fach studieren Sie?\n");
	scanf("%s", chPtr);
	getchar();
	setSubject(survey, chPtr);

	printf("In welchem Fachsemester befinden Sie sich? (1-12)\n");
	scanf("%hd", &temp);
	getchar();
	survey.year = temp;

	printf("Bitte benoten sie Ihre Übung in Schulonoten (1-6)\n");
	scanf("%hd", &temp);
	getchar();
	survey.rating = temp;

	printf("Weitere Anmerkungen?\n");
	//scanf("%s", chPtr);
	scanf("%[^\n]s",chPtr);
	getchar();
	//fgets (chPtr, 120, stdin);
	//*survey.remarks = *chPtr;
	strcpy(survey.remarks, chPtr);

	printForm(survey);

	return 0;
}