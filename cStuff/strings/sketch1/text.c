#include <stdio.h>
#include <string.h>

void track_search(char toSearch[]);
void revert(char * toRevert);
void replace_char(char *string, char toReplace, char replacement);
void normalize_space(char *string);


char tracks[][80] = {
	"I left foo",
	"Sie diesen Code der Reihe nach zusammensetzen",
	"Globale Variablen wie",
	"Schließlich folgen die Funktionen:",
	"Funktionen kennt, bevor er Ihren Code kompiliert"
};

int main(){

	char toSearch[80];
	printf("Search for:");
	scanf("%79s", toSearch);
	track_search(toSearch);
	replace_char(toSearch, '%', ' ');
	normalize_space(toSearch);
	printf("%s\n", toSearch);
	revert(toSearch);
	printf("%s\n", toSearch);
	return 0;

}

void track_search(char toSearch[]){
	int i;
	for(i = 0; i < 5; i++){
		if(strstr(tracks[i], toSearch)){
			printf("Track %i: '%s'\n", i, tracks[i]);
		}
	}
}

void revert(char * toRevert){
	char * startPtr = toRevert;
	char * endPtr = toRevert + strlen(toRevert) - 1;
	char buf;

	do {
		buf = *startPtr;
		*startPtr = *endPtr;
		*endPtr = buf;
	} while (startPtr++ < endPtr--);
}


void replace_char(char *string, char toReplace, char replacement){
	for(int i = 0; i < strlen(string); i++){
		if(string[i] == toReplace){
			string[i] = replacement;
		}
	}
}

void normalize_space(char *string){
	int i = 0;
	while(string[i] != '\0'){
		if(string[i] == ' ' && string[i+1] == ' '){
			memmove(string+i, string+i+1, strlen(string+i+1)+1);
		} else {
			i++;
		}
	}
}































