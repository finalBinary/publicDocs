#include <stdio.h>
#include <string.h>
#include "most_frequent2.h"



int isInArray(char toCheck, char *array);
int strIsInArray(char *toCheck);
int count_words(int *);
char allWords[80][81];


int main(){
    int count[80];
    char input[81];
    //int foo = 0;

    printf("Enter a text (max. 80 characters): \n");
    fgets(input, 81, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove trailing newline
    
    int number_of_words = extract_and_count(input, count);
    //count_words(count);
    
    print(number_of_words, count);
    
    printf("++++++++++++++++++++++++++++\n");
    printf("%d\n", number_of_words);
    printf("++++++++++++++++++++++++++++\n");
    printf("%s, %d\n", words[0], count[0]);
	printf("%s, %d\n", words[1], count[1]);
	printf("%s, %d\n", words[2], count[2]);
	printf("%s, %d\n", words[3], count[3]);
	printf("%s, %d\n", words[4], count[4]);
	printf("%s, %d\n", words[5], count[5]);
	printf("%s, %d\n", words[6], count[6]);
	printf("%s, %d\n", words[7], count[7]);

    return 0;
}


int extract_and_count(char *source,  int *count){
	
	char specials[] = {' ', '!', '?',','};
	char *	lastCopiedPtr = source;
	int wordIndex = 0;
	int firstRead = 0;
	
	for(int i = 0; i < strlen(source); i++){
		//printf("==> ");
		//printf("%c\n", source[i]);
		
		
		if (isInArray(source[i], specials) == 1 && firstRead == 1){
			int ptrPos = lastCopiedPtr - source; // position of ptr in word
			/*printf("last copied: %s\n", lastCopiedPtr);
			printf("%d\n", ptrPos);
			printf("%d\n", i);*/

			/*copy if next element is not an special*/
			if(ptrPos != i){
				strncpy(allWords[wordIndex], lastCopiedPtr, i-ptrPos); 
				lastCopiedPtr = lastCopiedPtr + (i-ptrPos);
				//printf("copied word: %s\n", allWords[wordIndex]);
				wordIndex ++;
			}
			
		
			/*copy special if not space*/
			if(*lastCopiedPtr != ' ' && lastCopiedPtr < (source + (strlen(source)-1)) ){
				strncpy(allWords[wordIndex], lastCopiedPtr, 1);
				//printf("copied special: %s\n", allWords[wordIndex]);
				wordIndex ++;
			}
			
			lastCopiedPtr++;
			
		/* if first special not found dont read*/	
		} else if (isInArray(source[i], specials) == 1 && firstRead == 0) {
			firstRead = 1;
			strncpy(allWords[wordIndex], lastCopiedPtr + i, 1);
			wordIndex ++;
			lastCopiedPtr = lastCopiedPtr + i +1;
		}
		//printf("=============== \n");
	}
	
	/*Copy last word if not yet copied and last char is special*/
	if(lastCopiedPtr < (source + (strlen(source)-1)) && isInArray(*(source + strlen(source)-1), specials)){
		//printf("last copy\n");
		//int foo =  (source + strlen(source)) - lastCopiedPtr;
		//strncpy(allWords[wordIndex], lastCopiedPtr, foo);
		strcpy(allWords[wordIndex], (source + strlen(source)-1));
		wordIndex ++;
	}
	
	
	printf("%s\n", allWords[0]);
	printf("%s\n", allWords[1]);
	printf("%s\n", allWords[2]);
	printf("%s\n", allWords[3]);
	printf("%s\n", allWords[4]);
	printf("%s\n", allWords[5]);
	printf("%s\n", allWords[6]);
	printf("%s\n", allWords[7]);
	printf("%s\n", allWords[8]);
	printf("%s\n", allWords[9]);
	printf("%s\n", allWords[10]);
	printf("%s\n", allWords[11]);
	printf("%s\n", allWords[12]);
	printf("%s\n", allWords[13]);
	printf("%s\n", allWords[14]);
	
	int nrWords = count_words(count);
	
	return nrWords;
}

int count_words(int *count){
	int index = 0;
	for(int i =0; i<80; i++){
		if(strIsInArray(allWords[i]) == -1){
			strcpy(words[index], allWords[i]); 
			*(count + index) = 1;
			index ++;
		}
		else{
			
			;count[strIsInArray(allWords[i])]++;
		}
	}
	return index + 1;
}

void print(int diff_words, int *count){
	int index = get_most_frequent_word(diff_words, count);
	printf("%s\n", allWords[index]);
}

int get_most_frequent_word(int number_of_words, int *count){
	//int index = 0;
	int maxNr = 0;
	for(int i = 0; i < number_of_words; i++) {
		if(*(count + i) > maxNr){
			maxNr = *(count +i);
		}
	}
	
	return maxNr;
}

int isInArray(char toCheck, char *array){
	for(int i = 0; i < strlen(array); i++){
		if(toCheck == array[i]) return 1;
	}
	return 0;
}

int strIsInArray(char *toCheck){
	for(int i = 0; i < 80; i++){
		if(strcmp(toCheck, words[i]) == 0) return i;
	}
	return -1;
}
