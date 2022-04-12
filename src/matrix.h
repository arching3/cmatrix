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
void mul_s(double, mat *);

void copy(double *, double *, size_t);
void swap(double *, double *);

mat *mat_init(int, int);
mat *mat_init_f(char *);
mat *mat_init_a(double *, int, int);
mat *mat_init_r(int, int, long int);
void mat_free(int, ...);


/*http://mwultong.blogspot.com/2006/10/c-gaussian-gaussian-random-numbers.html*/
double gaussrand();
