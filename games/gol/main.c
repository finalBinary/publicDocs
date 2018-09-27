#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
	int x;
	int y;
	int ** field;
} matrix;

matrix * buildMatrix(){
	static matrix * mat;
	mat = malloc(sizeof(matrix));

	mat->field = malloc(sizeof(int *));

	mat->x = 1;
	mat->y = 1;

	return mat;
}

void fillMatrix(matrix * mat, int width, int height){

	if(mat->y < height){
		mat->field = realloc(mat->field, sizeof(int *)*height);
	}

	mat->x = width;
	mat->y = height;
	for(int j = 0; j < height; j++){
		mat->field[j] = malloc(sizeof(int)*width);
		for(int i = 0; i < width; i++){
			mat->field[j][i] = 0;
		}
	}

}

void printMatrix(matrix * mat){
	printf("\n");
	for(int j = 0; j < mat->y; j++){
		for(int i = 0; i < mat->x; i++){
			if(mat->field[j][i] == 0){
				printf("  ");
			} else {
				printf("+ ");
			}
		}
		printf("\n");
	}
}

void freeMatrix(matrix * mat){
	for(int j = 0; j < mat->y; j++){
		free(mat->field[j]);
	}

	free(mat->field);
	free(mat);
}

void giveBirth(matrix * mat, int x, int y){
	if(mat->x > x && mat->y > y){
		mat->field[y][x] = 1;
	}
}

int countLivingNeighbours(matrix * mat, int x, int y){
	int count = 0;
	for(int i = -1; i < 2; i++){
		for(int j = -1; j < 2; j++){
			if(x+i >= 0 && x+i < mat->x && y+j >= 0 && y+j < mat->y && !(i == 0 && j == 0)){
				if(mat->field[y+j][x+i] == 1){
					count++;
				}
			}
		}
	}
	return count;
}

void evloveMatrix(matrix * mat){
	/*int ** evolvedField;
	evolvedField = malloc( (mat->x)*(mat->y)*sizeof(int) );
	memcpy(evolvedField, mat->field, (mat->x)*(mat->y)*sizeof(int));*/
	
	matrix *evolvedMatrix = buildMatrix();
	fillMatrix(evolvedMatrix, mat->x, mat->y);

	int currentCount = 0;
	for(int j = 0; j < mat->y; j++){
		for(int i = 0; i < mat->x; i++){
			//currentCount = countLivingNeighbours(mat, j, i);
			currentCount = countLivingNeighbours(mat, i, j);
			//printf("%d\n", currentCount);


			if(mat->field[j][i] == 0){

				if(currentCount == 3){
					evolvedMatrix->field[j][i] = 1;
				}
			}

			else if(mat->field[j][i] == 1){
				if(currentCount == 2 || currentCount == 3){
					evolvedMatrix->field[j][i] = 1;
				} else if(currentCount < 2){
					evolvedMatrix->field[j][i] = 0;					
				}
				else if(currentCount > 3){
					evolvedMatrix->field[j][i] = 0;
				}
			}

		}
	}

	int ** temp = mat->field;
	mat->field = evolvedMatrix->field;
	evolvedMatrix->field = temp;

	//free(evolvedField);
	freeMatrix(evolvedMatrix);
}

void delay(int del){
	int i = del * 1000000;
	while(i > 0){
		i--;
	}
}

void lifeCycles(matrix * mat, int cycles){
	while(cycles-- >0){
		delay(200);
		printf("\e[1;1H\e[2J");
		evloveMatrix(mat);
		printMatrix(mat);
	}	
}


int main(int argc, char * argv[]){

	matrix *bar = buildMatrix();
	fillMatrix(bar, 20, 20);
	
	//Glider
	/*
	giveBirth(bar, 2, 1);
	giveBirth(bar, 3, 2);
	giveBirth(bar, 3, 3);
	giveBirth(bar, 2, 3);
	giveBirth(bar, 1, 3);
	*/

	//
	giveBirth(bar, 1, 0);
	giveBirth(bar, 2, 0);
	giveBirth(bar, 3, 0);
	giveBirth(bar, 5, 0);
	giveBirth(bar, 6, 0);
	giveBirth(bar, 7, 0);

	giveBirth(bar, 0, 1);
	giveBirth(bar, 4, 1);
	giveBirth(bar, 8, 1);
	giveBirth(bar, 0, 2);
	giveBirth(bar, 4, 2);
	giveBirth(bar, 8, 2);
	giveBirth(bar, 0, 3);
	giveBirth(bar, 4, 3);
	giveBirth(bar, 8, 3);

	giveBirth(bar, 1, 4);
	giveBirth(bar, 2, 4);
	giveBirth(bar, 3, 4);
	giveBirth(bar, 5, 4);
	giveBirth(bar, 6, 4);
	giveBirth(bar, 7, 4);

	giveBirth(bar, 3, 5);
	giveBirth(bar, 5, 5);
	giveBirth(bar, 3, 6);
	giveBirth(bar, 5, 6);
	giveBirth(bar, 3, 7);
	giveBirth(bar, 5, 7);
	giveBirth(bar, 3, 8);
	giveBirth(bar, 5, 8);
	giveBirth(bar, 3, 9);
	giveBirth(bar, 5, 9);
	giveBirth(bar, 3, 10);
	giveBirth(bar, 5, 10);
	giveBirth(bar, 3, 11);
	giveBirth(bar, 5, 11);
	giveBirth(bar, 3, 12);
	giveBirth(bar, 5, 12);

	giveBirth(bar, 4, 13);
	

	


	//int fo = countLivingNeighbours(bar, 2, 1);
	//printf("%d\n", fo);

	printf("\e[1;1H\e[2J");

	printMatrix(bar);

	//delay(200);
	//printf("\e[1;1H\e[2J");
	/*printf("\n----------\n\n");
	evloveMatrix(bar);
	printMatrix(bar);
	
	delay(200);
	printf("\e[1;1H\e[2J");
	evloveMatrix(bar);
	printMatrix(bar);*/

	lifeCycles(bar, 10);



	freeMatrix(bar);

	return 0;
}
