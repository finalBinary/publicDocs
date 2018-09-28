#include <stdio.h>
#include <string.h>
#include "toUpper.h"

#define ASCII_a 	97 //corresponds to small a
#define ASCII_z 	122 //corresponds to small z
//ASCII_UPPER_DIFF corresponds to the numerical
// difference between upper and lower case letters
#define ASCII_UPPER_DIFF 	32 

void to_upper_char(char *small);
/*
 *main is commented out for tests
 */
/*int main(){
	char input1[81];
	char input2[81];

    printf("Enter a string (max. 80 characters): \n");
    fgets(input1, 80, stdin);
    input1[strcspn(input1, "\n")] = '\0'; // remove trailing newlinechar

    printf("Enter a second string (max. 80 characters): \n");
    fgets(input2, 80, stdin);
    input2[strcspn(input2, "\n")] = '\0'; // remove trailing newlinechar


    int cmp = compare_ignorecase(input1, input2);
    printf("Your entries have been transformed to:\n %s\nand\n %s \n", input1, input2);
    if(cmp == 0){
    	printf("Your entrys are equal after the transformation\n");
    } else {
    	printf("Your entrys are NOT equal after the transformation\n");
    }

    return 0;
}*/


/*Transform both strings to upercase, then compare them with strcmp*/
int compare_ignorecase(char * string1, char * string2){
	to_upper(string1);
	to_upper(string2);
	if(strcmp(string1, string2) == 0) return 0;
	return 1;
}

/* loop through all chars of a string an transform to uppercase*/
void to_upper(char *str){
	for(int i = 0; i < strlen(str); i++){
		to_upper_char(str+i);
	}
}

void to_upper_char(char *letter){

	/*if letter is lower case (97 <= letter <= 122) add 32 to get upper case letter*/
	if( (*letter + 0) >= ASCII_a && (*letter + 0)  <= ASCII_z ){
		*letter = *letter - ASCII_UPPER_DIFF;
	}
}