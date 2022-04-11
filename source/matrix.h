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

void *copy(double *, double *, size_t);
void swap(double *, double *);

mat *mat_init(FILE *);
mat *mat_init(double *, int, int);
mat *mat_init(int, int);

