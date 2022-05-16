typedef struct _MATRIX{
	double *arr;
	int r;
	int c;
} mat;

void print(mat *);

mat *add(mat *, mat *);
mat *sub(mat *, mat *);
mat *mul(mat *, mat *);
void mul_s(mat *,double);

int reshape(mat *, int, int);
void resize(mat *,int, int);

mat *mat_init(int, int);
mat *mat_init_f(char *);
mat *mat_init_a(double *, int, int);
mat *mat_init_r(int, int, long int);
mat *mat_copy(mat *);

int save(char *,mat *);

void trans(mat *);
void mat_free(int, ...);
