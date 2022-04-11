#include <stdio.h>
#include "matrix.h"


int main(){
	FILE *fp = fopen("test.txt","r");
	mat *matrix = mat_init(fp);
	fclose(fp);

	print(matrix);
	free(matrix->arr);
	free(matrix);
}
