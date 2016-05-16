

#include <stdio.h>
#include <stdlib.h>


int jlis_inner(int* a, int aSize, int aIdx, int* b, int bSize, int bIdx){

	static int** cache=NULL;

	if(NULL == a && NULL == b){
		free(cache);
		cache = NULL;
		return 0;
	}

	int i=0,j=0;

	if(NULL == cache){
		cache = (int**)malloc(sizeof(int*)*(aSize+1));
		for(i=0;i<=aSize;i++){
			cache[i] = (int*)malloc(sizeof(int)*(bSize+1));
			for(j=0;j<=bSize;j++){
				cache[i][j] = -1;
			}
		}
	}

	int* result = &cache[aIdx+1][bIdx+1];

	if(*result != -1)	{
		return *result;
	}

	*result = 2;

	//取较小的，加入自增序列，用较大的继续比较
	int a_tmp = aIdx == -1 ? -1 : a[aIdx];
	int b_tmp = bIdx == -1 ? -1 : b[bIdx];
	int max = a_tmp > b_tmp ? a_tmp : b_tmp;

	int tmp = -2;
	for(i=aIdx+1;i<aSize;i++){
		if(max < a[i]){
			tmp = jlis_inner(a, aSize, i, b, bSize, bIdx) + 1;
			if(tmp > *result){
				*result = tmp;
			}
		}
	}

	for(j=bIdx+1;j<bSize;j++){
		if(max < b[j]){
			tmp = jlis_inner(a, aSize, aIdx, b, bSize, j) + 1;
			if(tmp > *result){
				*result = tmp;
			}
		}
	}

	return *result;

}

int jlis(int* a, int aSize, int aIdx, int* b, int bSize, int bIdx){
	return jlis_inner(a, aSize, -1, b, bSize, -1);
} 

// int jlis(int* a, int aSize, int aIdx, int* b, int bSize, int bIdx){

// 	int i=0,j=0,max=-1,tmp=-1;

// 	for(i=0;i<aSize;i++){
// 		for(j=0;j<bSize;j++){
// 			tmp = jlis_inner(a, aSize, i, b, bSize, j);
// 			if(tmp > max){
// 				max = tmp;
// 			}
// 		}
// 	}
// 	return max;
// }


int main(int argc, char const *argv[])
{
	int a1[] = {1,2,4};
	int a2[] = {1,2,3};
	int a3[] = {10,20,30,1,2};

	int b1[] = {3,4,7};
	int b2[] = {4,5,6};
	int b3[] = {10,20,30};

	printf("%d\n", jlis(a1, 3, 0, b1, 3, 0));
	jlis(NULL, 3, 0, NULL, 3, 0);
	printf("%d\n", jlis(a2, 3, 0, b2, 3, 0));
	jlis(NULL, 3, 0, NULL, 3, 0);
	printf("%d\n", jlis(a3, 5, 0, b3, 3, 0));
	jlis(NULL, 3, 0, NULL, 3, 0);
	return 0;
}
