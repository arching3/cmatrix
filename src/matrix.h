#include <stdio.h>

typedef struct _MATRIX{
	double *arr;
	int r;
	int c;
} mat;

void print(mat *);

mat *add(mat *, mat *);
mat *sub(mat *, mat *);
mat *mul(mat *, mat *);

void copy(double *, double *, size_t);
void swap(double *, double *);

mat *mat_init_f(char *);
mat *mat_init_a(double *, int, int);
mat *mat_init_(int, int);

