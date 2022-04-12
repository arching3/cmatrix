# cmatrix
A library for calculating vectors and two-dimensional matrices.

C99 Standard.

## REFERENCE
|variable|etc|
|--------|---|
|`typedef struct mat`|`{int *arr--array, int r--row, int c-columm}`|

|functions|parm|desc|
|---------|----|----|
|`void print`|`(mat*)`|Print content of matrix.|
|`mat *add`|`(mat*, mat*)`|Add two matrix and return matrix pointer.|
|`mat *sub`|`(mat*, mat*)`|Sub two matrix and return matrix pointer.|
|`mat *mul`|`(mat*, mat*)`|Multiply two matrix and return matrix poitner.|
|`mat *mul_s`|`(double n, mat*)`|Scalar product.|
|`void swap`|`(double*, double*)`|Swap each other.|
|`mat *mat_init`|`(int r, int c)`|Initialize matrix to zero.|
|`mat *mat_init_f`|`(char*)`|Initialize matrix using data read from file and return matrix pointer.|
|`mat *mat_init_a`|`(double*arr, int r, int c)`|Initialize matrix using given 1d-array, row, columm and return matrix pointer.|
|`mat *mat_init_r`|`(int r, int c, long int seed)`|Initialize matrix using random number that based on gaussian-distribution.|
|`void mat_free`|`(int argc, ...)`| Release memory of matrix pointer in `...` |

## FILEFORMAT
In the first line, enter values for rows and columns, 

and separate each number with a space to create a matrix.
<pre>
2 4
3 421 5 2
55 12 3 4
</pre>

# USAGE
## FILL ZERO
```C
#include "matrix.h"
int main(){
	mat *matrix = mat_init(3,4);
	print(matrix);

	/*OUTPUT
	0.000,      0.000,      0.000,      0.000,
   	0.000,      0.000,      0.000,      0.000,
    	0.000,      0.000,      0.000,      0.000,
	*/

	mat_free(1,matrix);
}
```

## FROM FILE
```C
/*my_file.txt
  2 4
  3 421 5 2
  55 12 3 4
*/

#include "matrix.h"
int main(){
	mat *matrix = mat_init_f("my_file.txt");
	print(matrix);
	
	/*OUTPUT
	3.000,    421.000,      5.000,      2.000,
    	55.000,     12.000,      3.000,      4.000,
	*/

	mat_free(1,matrix);
}
```
## FROM 1D-ARRAY
```C
#inclue "matrix.h"

double array[] = {2.4, 5.1, 22.2, 3.6, 1.0, 2.0, 4.0, 2.0, 1.0};
int main(){
	mat *matrix = mat_init_a(array,3,3);
	/*!!The number of elements in the array and the r*c value must match!!*/
	print(matrix);
	
	/*OUTPUT
	3.000,      4.000,      2.000,
    	1.000,      2.000,      5.000,
    	2.000,      1.000,      2.000,
	*/

	mat_free(1,matrix);

}
```
## FILL RANDOM NUMBER
```C
#include <time.h> //This required to srand(time(NULL))

#include "matrix.h"
int main(){
	mat *matrix = mat_init_r(4,2,time(NULL));
	print(matrix);

	/*OUTPUT
	1.642,     -1.327,
     	0.738,      0.884,
    	-0.313,      0.324,
    	-0.658,      0.873,
	*/

	mat_free(1,matrix);
}
```

## BUILD
```
#1. This way is should be matrix.c in the same folder with main.c
#This way shoud be write preprocessor like #include "matrix.h"
gcc main.c matrix.c -lm


#2. This way is shoud be downloaded libmatrix.so and designate path.
gcc main.c -L{PATH} -lmatrix -lm

ex) libmatrix.so is in ~/library
gcc main.c -L~/library -lmatrix -lm

#This way should be write preprocessor like #include <matrix.h>

```
## SIMPLE EXAMPLE
```C
#include <stdio.h>
#include <time.h>
#include <matrix.h> //libmatrix.so

int main(){
	mat *m1 = mat_init_r(3,10,time(NULL));
	mat *m2 = mat_init_r(10,7,time(NULL));
	mat *result = mul(m1,m2);
	print(result);
	/*OUTPUT
	-3.672,     -3.639,      1.784,      0.039,      6.257,      3.690,     -2.566,
    	-2.228,      2.148,     -3.768,     -1.955,      0.138,      0.263,     -1.658,
     	2.780,     -2.793,      2.390,      4.821,      1.379,     -5.925,      7.295,
	*/

	mat_free(3,m1,m2,result);
}

```
