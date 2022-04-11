# cmatrix

이 저장소는 실제로 사용 가능한 프로그램을 기술하지 않습니다.

연습을 위한 저장소입니다.

# 목표
행렬의 사칙연산 구현과 웹에서 직접 쉘을 조작해 연산하는 기능까지 구현.

## Reference
|functions|parm|desc|
|---------|----|----|
|`void print`|`mat*`|print content of matrix.|
|`mat *add`|`(mat*, mat*)`|Add two matrix and return matrix pointer.|
|`mat *sub`|`(mat*, mat*)`|Sub two matrix and return matrix pointer.|
|`mat *mul`|`(mat*, mat*)`|Multiply two matrix and return matrix poitner.|
|`void copy`|`(double*, double*, size_t)`|Copies a portion of one array to another.|
|`void swap`|`(double*, double*)`|Swap each other.|
|`mat *mat_init_f`|`(FILE*)`|Initialize matrix using data read from file and return matrix pointer.|
|`mat *mat_init_a`|`(double*, int, int)`|Initialize matrix using given 1d-array, columm, row and return matrix pointer.|
|`mat *mat_init_n`|`(int, int)`|Initialize matrix using random number -- based on normal-distribution, given columm, row.|


## 파일포맷
첫 번째 행에서 행과 열의 값을 입력하고
행렬을 작성 합니다.

ex)
```
3 3
1 3 4
2 5 6
3 6 7

3 2
222 52
11 3
5 2
```
