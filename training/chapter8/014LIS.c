

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lis(char* str, int str_len, int idx){

	int result = 1;
	if(idx == str_len - 1){
		return result;
	}

	char prev = str[idx];
	char current = '\0';
	int i = idx+1;

	while((current = str[i++]) != '\0'){
		if(current > prev){
			prev = current;
			result++;
		}
	}

	int next_lis = lis(str, str_len, idx+1);

	return result > next_lis ? result : next_lis;
}

int lis2_inner(char* str, int str_len, int idx){

	static int* visited=NULL;

	if(NULL == str){
		free(visited);
		visited = NULL;
		return 0;
	}

	int i=0;
	if(NULL == visited){
		visited = (int*)malloc(sizeof(int)*str_len);
		for(i=0;i<str_len;i++){
			visited[i] = -1;
		}
	}

	int* result  = &visited[idx];

	if(*result != -1){
		return *result;
	}

	*result = 1;

	char prev = str[idx];
	char current = '\0';
	i = idx+1;

	while((current = str[i]) != '\0'){
		if(current > prev){
			int next_lis = lis2_inner(str, str_len, i);
			if(next_lis + 1 > *result){
				*result = next_lis + 1;
			}
		}
		i++;
	}

	return *result;
}

int lis2(char* str, int str_len, int idx){

	int result = 0;
	int tmp = 0;
	int i=0;
	for(i=0;i<str_len;i++){
		tmp = lis2_inner(str, str_len, i);
		if(tmp > result){
			result = tmp;
		}
	}
	return result;
}


int main(int argc, char const *argv[])
{
	printf("%d\n", lis("1244353", 7, 0));
	printf("%d\n", lis2("1244353", 7, 0));
	lis2(NULL, 7,0);
	printf("%d\n", lis("3124353", 7, 0));
	printf("%d\n", lis2("3124353", 7, 0));
	return 0;
}
