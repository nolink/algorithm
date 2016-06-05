


#include <stdio.h>

int cache[10][6] = {0};

int packing(int* sizes, int* importance, int len, int max_size, int idx){	

	if(idx == len){
		return 0;
	}

	int yes = 0;
	if(sizes[idx] <= max_size){
		yes = importance[idx] + packing(sizes, importance, len, max_size - sizes[idx], idx+1);	
	}
	
	int no = packing(sizes, importance, len, max_size, idx+1);

	return yes > no ? yes : no;
}



int main(int argc, char const *argv[])
{
	int sizes1[] = {4, 2, 6, 4, 2, 10};
	int importance1[] = {7, 10, 6, 7, 5, 4};
	printf("%d\n", packing(sizes1, importance1, 6, 10, 0));
	return 0;
}
