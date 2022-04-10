#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

char *cmd = {"-a", "-p", "-s"};
m *matrix(int argc, char *args[]){

	FILE *file = fopen(args[1],"w");
	if(file == NULL){
		return NULL;
	}

	char *mod = args[2];
	m **mat = (m **)malloc(sizeof(m*)*2);
	mat = proc_file(file);
	m result;
}


m **proc_file(FILE *file){
	m **temp = (m**)malloc(sizeof(m*)*2);
	temp[0] = (m*)malloc(sizeof(m));
	temp[1] = (m*)malloc(sizeof(m));
	int idx=0;
	int stat=0;
	while(!feof(file)){
		char t = fgetc(file);
		else if(t == '\n'){
			temp[stat]->r++;
		}
		if(t == 'e'){	
		}
	}
}
m *add(m* m1, m* m2){}
m *sub(m* m1, m* m2){}
m *mul(m* m1, m* m2){}
void print(m* rs){}
