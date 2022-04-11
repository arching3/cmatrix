#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

char *cmd = {"-a", "-p", "-s"};
m *matrix(int argc, char *args[]){

	FILE *file = fopen(args[1],"r");
	if(file == NULL){
		return NULL;
	}

	char *mod = args[2];
	m **mat = (m **)malloc(sizeof(m*)*2);
	mat = proc_file(file);
	fclose(file);


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
		if(t == ' ')idx++;
		if(t == '\n'){
			temp[stat]->r++;
			idx=0;
		}
		else if(t == 'e'){
			temp[stat]->r++;
			idx--;
			temp[stat]->c=idx;
			stat != stat;
		}
	}

	temp[0]->arr = (int *)malloc(sizeof(int)*temp[0]->c*temp[0]->r)
	temp[1]->arr = (int *)malloc(sizeof(int)*temp[1]->c*temp[1]->r)
	stat!=stat;
	idx=0;
	rewind(file);
	while(!feof(file)){
		char te[300];
		for(int i = 0;i<temp[stat]->r;i++){
			for(int j = 0;j<temp[stat]->c;j++){
			fscanf("%s",te);
			if(te=="e")break;
			arr[idx] = atoi(te);
			}
		}
	}
	return temp;
}
m *add(m* m1, m* m2){}
m *sub(m* m1, m* m2){}
m *mul(m* m1, m* m2){}
void print(m* rs){}
