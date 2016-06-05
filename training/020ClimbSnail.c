

#include <stdio.h>
#include <stdlib.h>

int can_climb(int n, int m, int passedDays, int climbed){

	static int** cache=NULL;

	if(n == -1 && m == -1){
		free(cache);
		cache = NULL;
		return 0;
	}

	int i=0, j=0;
	if(NULL == cache){
		int size = n*2+1;
		cache = (int**)malloc(sizeof(int*)*n);
		for(i=0;i<n;i++){
			cache[i] = (int*)malloc(sizeof(int)*size);
			for(j=0;j<size;j++){
				cache[i][j] = -1;
			}
		}
	}

	if(passedDays >= n){
		return climbed >= m;
	}

	int* result = &cache[passedDays][climbed];

	if(-1 != *result){
		return *result;
	}

	return can_climb(n, m, passedDays+1, climbed + 1) + can_climb(n, m, passedDays+1, climbed+2);
}


int main(int argc, char const *argv[])
{
	
	printf("%d\n", can_climb(2, 3, 0, 0));

	return 0;
}