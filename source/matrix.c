#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


void print(mat *matrix){
	for(int i = 0;i<matrix->r*matrix->c;i++){
		printf("%f, ",matrix->arr[i]);
		if(((i+1)%matrix->r)==0){
			printf("\n");
		}
	}
}


mat *mat_init_f(char *name){
	mat *matrix = (mat *)malloc(sizeof(mat));

	FILE *fp = fopen(name,"r");
	fscanf(fp,"%d %d",&matrix->r,&matrix->c);
	matrix->arr = (double *)malloc(sizeof(double)*(matrix->r*matrix->c));
	for(int i = 0;i<matrix->r*matrix->c;i++){
		fscanf(fp,"%lf",&matrix->arr[i]);
	}
	fclose(fp);
	return matrix;
}


mat *mat_init_a(double *arr, int c, int r){
	mat *matrix = (mat *)malloc(sizeof(mat));
	return matrix;
}
mat *mat_init_n(int c, int r){}

void copy(double *dest, double *src, size_t size){}
void swap(double *a, double *b){};

mat *add(mat *m1, mat *m2){}
mat *sub(mat *m1, mat *m2){}
mat *mul(mat *m1, mat *m2){}
