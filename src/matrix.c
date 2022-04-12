#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

#include "matrix.h"

double gaussrand();

void print(mat *matrix){
	if(matrix==NULL){
		printf("CANNOT PRINT. THE MATRIX IS POINTING NULL\n");		
	}
	else{
		for(int i = 0;i<matrix->r*matrix->c;i++){
			printf("%10.3f, ",matrix->arr[i]);
			if(((i+1)%matrix->c)==0){
				printf("\n");
			}
		}
	}
}

mat *mat_init(int r, int c){
	mat *matrix = (mat *)malloc(sizeof(mat));
	matrix->arr = (double *)malloc(sizeof(double)*(r*c));
	for(int i = 0;i<r*c;i++){
		matrix->arr[i] = 0;
	}
	matrix->r=r;
	matrix->c=c;
	return matrix;
}

mat *mat_init_f(char *name){
	mat *matrix = (mat *)malloc(sizeof(mat));

	FILE *fp = fopen(name,"r");
	if(fp==NULL){
		printf("%s DOES NOT EXIST.\n",name);
		return NULL;
	}
	fscanf(fp,"%d %d",&matrix->r,&matrix->c);
	matrix->arr = (double *)malloc(sizeof(double)*(matrix->r*matrix->c));
	for(int i = 0;i<matrix->r*matrix->c;i++){
		fscanf(fp,"%lf",&matrix->arr[i]);
	}
	fclose(fp);
	return matrix;
}

mat *mat_init_a(double *arr, int r, int c){
	mat *matrix = (mat *)malloc(sizeof(mat));
	matrix->arr = (double *)malloc(sizeof(double)*(r*c));
	for(int i = 0;i<r*c;i++){
		matrix->arr[i] = arr[i];
	}
	matrix->c = c;
	matrix->r = r;
	return matrix;
}

mat *mat_init_r(int r, int c, long int seed){
	static int overlap=0;
	srand(seed+overlap);
	mat *matrix = (mat *)malloc(sizeof(mat));
	matrix->arr = (double *)malloc(sizeof(double)*(r*c));
	
	for(int i = 0;i<r*c;i++){
		matrix->arr[i] = gaussrand();
	}

	matrix->r = r;
	matrix->c = c;
	overlap++;
	return matrix;
}

//http://mwultong.blogspot.com/2006/10/c-gaussian-gaussian-random-numbers.html
double gaussrand(){
	static double v1,v2,s;
	static int phase = 0;
	double x;

	if(phase==0){
		do{
			double u1 = (double)rand() / RAND_MAX;
			double u2 = (double)rand() / RAND_MAX;
			v1 = 2 * u1 -1;
			v2 = 2 * u2 - 1;
			s = v1 * v1 + v2 * v2;
		}
		while(s>=1 || s==0);
		x = v1*sqrt(-2*log(s)/s);
	}
	else x = v2 * sqrt(-2 * log(s) / s);

	phase = 1 - phase;
	return x;
}

void swap(double *a, double *b){
	double t = *a;
	*a = *b;
	*b = t;
}

mat *add(mat *m1, mat *m2){
	if(m1->r != m2->r || m1->c != m2->c){
		return NULL;
	}
	mat *result = mat_init(m1->r,m1->c);
	for(int i = 0;i<m1->r*m1->c;i++){
		result->arr[i] = m1->arr[i]+m2->arr[i];
	}
	return result;
}

mat *sub(mat *m1, mat *m2){
	if(m1->r != m2->r || m1->c != m2->c){
		return NULL;
	}
	mat *result = mat_init(m1->r,m1->c);
	for(int i = 0;i<m1->r*m1->c;i++){
		result->arr[i] = m1->arr[i]-m2->arr[i];
	}
	return result;
}

mat *mul(mat *m1, mat *m2){
	if(m1->c != m2->r){
		printf("FAIL - columm num of A and row num of B does not match\n");
		return NULL;
	}
	mat *result = mat_init(m1->r,m2->c);
	double temp = 0;		
	int i=0,j=0,idx=0;
	for(int o = 0;o<m1->r;o++){
		for(int w = 0;w<m2->c;w++){
			i=o*m1->c;
			j=w;
			for(int m = m1->c;m--;){
				temp += m1->arr[i]*m2->arr[j];
				i++;
				j += m2->c;
			}
			result->arr[idx++]=temp;
			temp = 0;
		}
	}
	return result;
}

void mul_s(double x, mat *matrix){
	for(int i = 0;i<matrix->r*matrix->c;i++){
		matrix->arr[i] *= x;
	}
}

void mat_free(int argc, ...){
	va_list ap;
	va_start(ap, argc);
	for(int i = 0;i<argc;i++){
		mat* matrix = va_arg(ap, mat*);
		if(matrix!=NULL){
			free(matrix->arr);
			free(matrix);
		}
	}
	va_end(ap);
}
