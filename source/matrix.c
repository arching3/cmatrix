#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


void print(mat *matrix){
	for(int i = 0;i<mat->r*mat->c;i++){
		printf("%f, ",mat->arr[i]);
		if(((i+1)%mat->r)==0){
			printf("\n");
		}
	}
}
mat *mat_init(FILE *fp){
	mat *matrix = (mat *)malloc(sizeof(mat));
	int c,r;
	fscanf(fp,"%f %f",&r,&c);
	matrix->r=r;
	matrix->c=c;
	matrix->arr = (double *)malloc(sizeof(double)*(r*c));
	for(int i = 0;i<r*c;){
		if(!fscanf("%f",matrix->&arr[i])){
			matrix->arr[i] = 0;
		};
	}
	return matrix;
}
mat *mat_init(double *arr, int c, int r){}
mat *mat_init(int c, int r){}

void copy(double *dest, double *src, size_t size){}
void swap(double *a, double *b){};

mat *add(mat *m1, mat *m2){}
mat *sub(mat *m1, mat *m2){}
mat *mul(mat *m1, mat *m2){}
