#include <stdio.h>
#include "matrix.h"


int main(int argc, char* args[]){
	if(argc==1){
		printf("파일을 입력해주세요");
		return 0;
	}
	m *result = matrix(argc,args);
	if(result==NULL){
		printf("파일이 존재하지 않거나 옵션이 잘못됐습니다.");
			return 0;
	}
	print(result);
}
