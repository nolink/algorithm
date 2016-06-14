

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* vals;
    int size;
    int capacity;
} stack;

stack* create(int capacity){
    stack* s = (stack*)malloc(sizeof(stack));
    s->capacity = capacity;
    s->size = 0;
    s->vals = (int*)malloc(sizeof(int)*capacity);
}

int push(stack* s, int val){

	(s->size)++;

	s->vals[s->size -1] = val;
	
	// if(s->size == s->capacity){
	// 	void* tmp = realloc(s->vals, (s->capacity)*2);
	// 　　if (tmp == NULL) {
	// 　　    free(s);
	// 　　    return 0;
	// 　　}
	// 　　s->vals = (stack*)tmp;
	// }
	return 1;
}

int top(stack* s){
	return s->vals[s->size - 1];
}

void pop(stack* s){
	(s->size)--;
}

void destroy(stack* s){
	free(s->vals);
	free(s);
}


int brackets2(char* str){

	int len = strlen(str);
	stack* s = create(len);

	int i=0;
	for(;i<len;i++){
		if(str[i] == '(' || str[i] == '{' || str[i] == '['){
			push(s, str[i]);
		}else{
			if(s->size == 0){
				return 0;
			}
			int v = top(s);
			if((str[i] == ')' && v == '(') || (str[i] == ']' && v == '[') || (str[i] == '}' && v == '{') ){
				pop(s);
			}else{
				return 0;
			}
		}
	}

	int result = s->size == 0;

	destroy(s);
	return result;

}


int main(int argc, char const *argv[])
{
	printf("%d\n", brackets2("({[}])})"));
	return 0;
}
