#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>
int main(){
	mat *matrix = mat_init_f("test.txt");
	if(matrix == NULL){
		printf("\n\n\n!====SOMETHING WENT WRONG====!\n");
		free(matrix);
		return 0;
	}

	print(matrix);
	free(matrix->arr);
	free(matrix);
}
