#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int len;
	int fill;
	char str[];
} dynArr;

dynArr * buildArr(){
	static dynArr * arr;
	arr = malloc(sizeof(dynArr) + sizeof(char));
	//arr = malloc(sizeof(dynArr));
	arr->len = 1;
	arr->fill = 0;

	return arr;
}

void doubleArr(dynArr ** arr){
	printf("\t => doubling <=\n");
	dynArr * temp = realloc(*arr, sizeof(dynArr) + 2*((*arr)->len)*sizeof(char));

	if(temp){
		*arr = temp;
		(*arr)->len = 2*( (*arr)->len );
	} else{
		printf("No Memory\n");
	}

}

void halfArr(dynArr ** arr){
	printf("\t => half <=\n");
	//arr = realloc(arr, sizeof(dynArr) + (arr->len)*sizeof(char)/2);
	//arr->len = arr->len/2;

	dynArr * temp = realloc(*arr, sizeof(dynArr) + ((*arr)->len)*sizeof(char)/2);

	if(temp){
		*arr = temp;
		(*arr)->len = ( (*arr)->len )/2;
	} else{
		printf("No Memory\n");
	}

}

void removeElement(dynArr ** arr, char element){
	short found = 0;
	for(int i = 0; i< (*arr)->len-1; i++){
		if((*arr)->str[i] == element){
			found = 1;
		}

		if(found){
			(*arr)->str[i] = (*arr)->str[i+1];
		}
	}

	(*arr)->fill--;

	if((*arr)->fill <= (*arr)->len/2){
		halfArr(arr);
	}
}

void addElement(dynArr ** arr, char element){
	if((*arr)->fill + 1 > (*arr)->len){
		doubleArr(arr);
	}
	(*arr)->str[(*arr)->fill] = element;
	//arr->fill= arr->fill +1;
	(*arr)->fill++;
}

void printArr(dynArr ** arr){
	printf("len: %d\n", (*arr)->len);
	for(int i =0; i < (*arr)->fill; i++){
		printf("%c", (*arr)->str[i]);
	}
	printf("_\n");
}

int main(int argc, char * argv[]){

	dynArr **bar;
	dynArr *foo = buildArr();
	bar = &foo;
	//doubleArr(&foo);
	//dynArr * temp = realloc(foo, sizeof(dynArr) + 2*(foo->len)*sizeof(char));
	//foo = temp;

	addElement(bar, 'a');
	//printArr(*bar);
	addElement(bar, 'b');
	//printArr(*bar);

	addElement(bar, 'c');
	addElement(bar, 'x');
	addElement(bar, 'd');
	printArr(bar);

	removeElement(bar, 'x');
	printArr(bar);
	//foo->str[10] = 'a';
	//free(foo->str);
	free(foo);
	return 0;
}
