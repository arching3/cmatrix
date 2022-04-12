# cmatrix

이 저장소는 실제로 사용 가능한 프로그램을 기술하지 않습니다.

연습을 위한 저장소입니다.

# 목표
행렬의 사칙연산 구현과 웹에서 직접 쉘을 조작해 연산하는 기능까지 구현.

## Reference
|variable|etc|
|--------|---|
|`typedef struct mat`|`{int *arr--array, int r--row, int c-columm}`|


|functions|parm|desc|
|---------|----|----|
|`void print`|`mat*`|Print content of matrix.|
|`mat *add`|`(mat*, mat*)`|Add two matrix and return matrix pointer.|
|`mat *sub`|`(mat*, mat*)`|Sub two matrix and return matrix pointer.|
|`mat *mul`|`(mat*, mat*)`|Multiply two matrix and return matrix poitner.|
|`mat *mul_s`|`(double, mat*)`|Scalar product.|
|`void copy`|`(double*dest, double*src, size_t)`|Copies a portion of src to dest.|
|`void swap`|`(double*, double*)`|Swap each other.|
|`mat *mat_init`|`(int, int)`|Initialize matrix to zero.|
|`mat *mat_init_f`|`(FILE*)`|Initialize matrix using data read from file and return matrix pointer.|
|`mat *mat_init_a`|`(double*, int, int)`|Initialize matrix using given 1d-array, row, columm and return matrix pointer.|
|`mat *mat_init_r`|`(int, int, long int)`|Initialize matrix using random number that based on gaussian-distribution.|
|`void mat_free`|`(int, ...)`| Release memory of matrix pointer in `...` |

## 파일포맷
첫 줄에서 행과 열의 값을 입력하고
행렬을 작성 합니다.

> ex)

> 2 4

> 3 6 2 4

> 2 12 52 1

