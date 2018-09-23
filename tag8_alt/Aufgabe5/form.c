#include <stdio.h>
#include <string.h>

#include "form.h"

void setSubject(struct form survey, char * subject){
	if(strcmp("Informatik", subject)){
		survey.subject = Informatik;
	}
	else if(strcmp("Mathematik", subject)){
		survey.subject = Mathematik;
	}
	else if(strcmp("Physik", subject)){
		survey.subject = Physik;
	}
}

void printForm(struct form survey){
	switch(survey.subject){
		case Informatik: printf("Informatik\n"); break;
		case Mathematik: printf("Mathematik\n"); break;
		case Physik: printf("Physik\n"); break;
	}
	printf("%d\n", survey.year);
	printf("%d\n", survey.rating);
	printf("%s\n", survey.remarks);
}