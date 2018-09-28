#include <stdio.h>

int warte_Auf_eingabe();

void ei_ausgeben(int anzal, int *geldstand, int * schokostand);
void ei_kaufen(int anzal, int *geldstand, int * schokostand);
void kaseete_leeren(int *geldstand);
int keine_eier(int * schokostand);

int main(){
	
	int schokostand = 500;
	int geldstand = 0;
	
	while(schokostand > 0){
		printf("Wie viele Überraschungseier sollen gekauft werden?\n");
		int anzahl = warte_Auf_eingabe();
		ei_kaufen(anzahl, &geldstand, &schokostand);
		ei_ausgeben(anzahl, &geldstand, &schokostand);
	}
	
	keine_eier(&schokostand);
	
	return 0;
}

int warte_Auf_eingabe(){
	int eingabe;
	scanf("%d", &eingabe);
	
	return eingabe;
}

void ei_kaufen(int anzal, int *geldstand, int * schokostand){
	for(int i=0; i< anzal; i++){
		kaseete_leeren(geldstand);
		if( keine_eier(schokostand) != 0) break;
		*geldstand = *geldstand +  50;
		*schokostand = *schokostand - 1;
	}
}

void ei_ausgeben(int anzal, int *geldstand, int * schokostand){
	
	printf("Hier sind deine Überraschungseier:\n");
	
	for(int i = 0; i< anzal; i++){
			printf("O\n");
	}
}

void kaseete_leeren(int *geldstand){
	char msg;
	if(*geldstand >= 10000){
		printf("Kasette leeren!!!\n");
		scanf("%s", &msg);
		if(msg == 'y') *geldstand = 0;
	}
}

int keine_eier(int * schokostand){
	if(*schokostand <= 0){
		printf("Keine Eier mehr!!\n");
		return 1;
	}
	
	return 0;
}
