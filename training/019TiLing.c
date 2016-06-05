

#include <stdio.h>


int cache[100]={0};

int tiling(int n){

	if(n == 1 || n == 2){
		return n;
	}

	int* result = &cache[n];

	if(*result != 0){
		return *result;
	}

	return *result = tiling(n-1) + tiling(n-2);
}


int main(int argc, char const *argv[])
{	
	printf("%d\n", tiling(5));
	return 0;
}
