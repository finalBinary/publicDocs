#include <stdio.h>
#include <string.h>
#include "most_frequent2.h"


int main(){
    int count[80];
    char input[81];

    printf("Enter a text (max. 80 characters): \n");
    fgets(input, 81, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove trailing newline
    
    int number_of_words = extract_and_count(input, count);
    
    print(number_of_words, count);

    return 0;
}
