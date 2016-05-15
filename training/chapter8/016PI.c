

#include <stdio.h>
#include <stdlib.h>

//3-5位字符
int hardness(char* str, int fromInclu, int toExclu){
    
    int ret = 10;

    int i=fromInclu;
    int allSame = 1;
    for(;i<toExclu;i++){
    	if(str[fromInclu] != str[i]){
    		allSame = 0;
    		break;
    	}
    }

    if(allSame){
    	return 1;
    }

    int len = toExclu - fromInclu;

    //交替出现，或其他情况
    if(str[fromInclu+2] == str[fromInclu]){
    	ret = len == 3 || (len == 4 && str[fromInclu+1] == str[fromInclu+3]) 
    		|| (len == 5 && (str[fromInclu+1] == str[fromInclu+3] && str[fromInclu] == str[fromInclu+4])) ? 4 : 10;
    }else{
    	int sub = str[fromInclu] - str[fromInclu+1];
		for(i=fromInclu+2;i<toExclu;i++){
			if(str[i-1] - str[i] != sub){
				return 10;
			}
		}
		ret = sub == 1 || sub == -1 ? 2 : 5;
    }

    return ret;
}



int pi(char* str, int size, int idx){

	static int* cache=NULL;

	if(NULL == str){
		free(cache);
		cache = NULL;
		return 0;
	}

	int i=0;
	if(NULL == cache){
		cache = (int*)malloc(sizeof(int)*size);
		for(i=0;i<size;i++){
			cache[i] = -1;
		}
	}

	if(idx >= size){
		return 0;
	}

	int *ret = &cache[idx];

	if(*ret != -1){
		return *ret;
	}
	int tmp = 0;
	*ret = tmp = 99999999;

	if(idx + 3 <= size){
		tmp = hardness(str, idx, idx+3) + pi(str, size, idx+3);
		if(tmp < *ret){
			*ret = tmp;
		}
	}
	if(idx + 4 <= size){
		tmp = hardness(str, idx, idx+4) + pi(str, size, idx+4);
		if(tmp < *ret){
			*ret = tmp;
		}
	}
	if(idx + 5 <= size){
		tmp = hardness(str, idx, idx+5) + pi(str, size, idx+5);
		if(tmp < *ret){
			*ret = tmp;
		}
	}

	return *ret;
}



int main(int argc, char const *argv[])
{
	// printf("%d\n", hardness("333", 0, 3));
	// printf("%d\n", hardness("5555", 0, 4));
	// printf("%d\n", hardness("23456", 0, 5));
	// printf("%d\n", hardness("3210", 0, 4));
	// printf("%d\n", hardness("323", 0, 3));
	// printf("%d\n", hardness("54545", 0, 5));
	// printf("%d\n", hardness("147", 0, 3));
	// printf("%d\n", hardness("8642", 0, 4));
	// printf("%d\n", hardness("17912", 0, 5));
	// printf("%d\n", hardness("331", 0, 3));
	printf("%d\n", pi("12341234", 8, 0));
	pi(NULL, 8, 0);
	printf("%d\n", pi("11111222", 8, 0));
	pi(NULL, 8, 0);
	printf("%d\n", pi("12122222", 8, 0));
	pi(NULL, 8, 0);
	printf("%d\n", pi("22222222", 8, 0));
	pi(NULL, 8, 0);
	printf("%d\n", pi("12673939", 8, 0));
	pi(NULL, 8, 0);
	return 0;
}