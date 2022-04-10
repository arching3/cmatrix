#include <stdio.h>

typedef struct _MATRIX{
	int *arr;
	int c;
	int r;
}m;
m *matrix(int, char*[]);
	
m **proc_file(FILE *);
m *add(m*, m*);
m *sub(m*, m*);
m *mul(m*, m*);
void print(m*);
