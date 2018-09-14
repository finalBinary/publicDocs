#include <stdio.h>
#include <string.h>
#include "most_frequent2.h"

void extract_noraml_words(char *source, char *extracted);
void extract_and_rplace_specials(char *source, char *extracted);
void initialize_to_empty(char *wordArray);
int count_and_assign_words(int *count, char * toCount, int offset);
int chrIsInArray(char toCheck, char *array);
int strIsInWordsArray(char *toCheck);
void normalize_space(char *string);

#define MAX_CHARS  80

/*
 *main is commented out for tests
 */
/*int main(){
    int count[MAX_CHARS] = {0};
    char input[MAX_CHARS+1];

    printf("Enter a text (max. %d characters): \n", MAX_CHARS);
    fgets(input, MAX_CHARS+1, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove trailing newline
    
    int number_of_words = extract_and_count(input, count);
    printf("NR of Word: %d\n", number_of_words);
    
    print(number_of_words, count);
    

    return 0;
}*/


int extract_and_count(char *source,  int *count){
		
	char foundWords[MAX_CHARS][MAX_CHARS+1]; //normal words are stored here
	char foundSpecials[MAX_CHARS][MAX_CHARS+1]; //special chars are stored here

	/* initializing to a defined state */
	initialize_to_empty(foundWords[0]);
	initialize_to_empty(foundSpecials[0]);

	/* extract special characters and words from input string */
	extract_and_rplace_specials(source, foundSpecials[0]);
	extract_noraml_words(source, foundWords[0]);

	/* count special characters and words */
	int nrOfWords = count_and_assign_words(count, foundWords[0], 0);
	nrOfWords = count_and_assign_words(count, foundSpecials[0], nrOfWords);

	return nrOfWords;
}


void print(int diff_words, int *count){
	int index = get_most_frequent_word(diff_words, count);
	printf("%s\n", words[index]);
}


int get_most_frequent_word(int number_of_words, int *count){
	int maxNr = 0;
	int index = 0;

	for(int i = 0; i < number_of_words; i++) {
		if(*(count + i) > maxNr){
			index = i;
			maxNr = *(count +i);
		}
	}
	
	return index;
}

/*
 * splits a string by single white spaces, these strings are added to
 * the storage array 'extracted'
 */
void extract_noraml_words(char *source, char *extracted){
	char spacer[] = " ";
	char *currentWordPtr = strtok(source, spacer); // splitt by white space

	int index = 0; // marks position in extracted
	while(currentWordPtr != NULL) {
		strcpy( (extracted+index*(MAX_CHARS+1)), currentWordPtr);
		currentWordPtr = strtok(NULL, spacer); // move 'currentWordPtr' to next word
		index++;
	}
}

/*
 * loops through string, if a special character is found it is added to
 * the storage array 'extracted', and the special character gets replaced
 * by a space
 */
void extract_and_rplace_specials(char *source, char *extracted){
	char specials[] = {'!', '?',',', '.'};

	int index = 0; // marks position in extracted
	for(int i = 0; i < strlen(source); i++){
		/* if char is a special character */
		if(chrIsInArray( *(source+i), specials)) {
			strncpy( (extracted+index*(MAX_CHARS+1)), (source+i), 1); // add to extracted
			*(source+i) = ' '; // replace by white space
			index++;
		}
	}
}

/*
 * fills a 2-D array with '\0' to have a defined state
 */
void initialize_to_empty(char *wordArray){
	for(int i = 0; i < MAX_CHARS; i++){
		*(wordArray+i*(MAX_CHARS+1)) = '\0';
	}
}


/*
 * loops through string array and assigns unique words to the global words array
 * also counts the unique words
 */
int count_and_assign_words(int *count, char * toCount, int offset){
	int index = offset;
	for(int i =0; i<MAX_CHARS; i++){
		/* if word is not yet in the words array*/
		if(*(toCount+i*(MAX_CHARS+1)) != '\0'
			&& strIsInWordsArray( (toCount+i*(MAX_CHARS+1)) ) == -1){

			strcpy(words[index], (toCount+i*(MAX_CHARS+1)) ); // add word to words array
			*(count + index) = 1; // ad new entry of one to count array
			index ++;
		}
		/* else word is already in the words array*/
		else{
			
			count[strIsInWordsArray( (toCount+i*(MAX_CHARS+1)) )]++; // increment the count
		}
	}
	return index;
}

/*
 * checks if a given char is in an given char array
 */
int chrIsInArray(char toCheck, char *array){
	for(int i = 0; i < strlen(array); i++){
		if(toCheck == array[i]) return 1;
	}
	return 0;
}

/*
 * checks if a given string is in the global words array
 */
int strIsInWordsArray(char *toCheck){
	for(int i = 0; i < MAX_CHARS; i++){
		if(strcmp(toCheck, words[i]) == 0) return i;
	}
	return -1;
}

/*
 * reduces all multiple spaces to one
 */
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
