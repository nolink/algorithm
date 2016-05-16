

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int* normalize(int* a, int* sizeA){

	int i=0,j=0;

	for(i=0;i<(*sizeA)-1;i++){
		if(a[i] < 0){
			int shift = (abs(a[i])+9) / 10;
			a[i+1] -= shift;
			a[i] += shift * 10;
			
		}else{
			a[i+1] += a[i] / 10;
			a[i] %= 10;	
		}
	}

	for(i=(*sizeA)-1;i>=0;i--){
		if(a[i] != 0) break;
	}

	int* result = (int*)malloc(sizeof(int)*(i+1));

	for(j=0;j<=i;j++){
		result[j] = a[j];
	}

	*sizeA = i+1;
	free(a);
	return result;

}

int* big_multiply(int* a, int sizeA, int* b, int sizeB, int* resultSize){

	int i=0,j=0;
	*resultSize = sizeA+sizeB+1;
	int* result = (int*)malloc(sizeof(int)*(*resultSize));
	for(i=0;i<(*resultSize);i++){
		result[i] = 0;
	}

	for(i=0;i<sizeA;i++){
		for(j=0;j<sizeB;j++){
			result[i+j] += a[i]*b[j];
		}
	}

	return normalize(result, resultSize);
}

// a + b*10^k
int* add(int* a, int sizeA, int* b, int sizeB, int k, int* resultSize){

	int resultBSize = (sizeB + k > sizeA) ? sizeB + k : sizeA;

	int i=0;

	int* result = (int*)malloc(sizeof(int)*resultBSize);

	for(i=0;i<k;i++){
		result[i] = 0;
	}
	for(i=0;i<sizeB;i++){
		result[i+k] = b[i];
	}



}

int* sub(int* a, int sizeA, int* b, int sizeB, int* resultSize){

}

int* karatsuba(int* a, int sizeA, int* b, int sizeB, int* resultSize){

	if(sizeA < sizeB){
		return karatsuba(b, sizeB, a, sizeA, resultSize);
	}

	if(sizeA == 0 || sizeB == 0){
		return NULL;
	}

	if(sizeA <= 50){
		return big_multiply(a, sizeA, b, sizeB, resultSize);
	}

	int mid = sizeA / 2;
	int i=0;

	int* a0 = (int*)malloc(sizeof(int)*mid);
	int* a1 = (int*)malloc(sizeof(int)*(sizeA - mid));
	
	for(i=0;i<mid;i++){
		a0[i] = a[i];
	}
	for(i=0;i<sizeA - mid;i++){
		a1[i] = a[mid+i];
	}

	int* ret = NULL;
	int ret_size = 0;
	if(mid < sizeB){
		int* b0 = (int*)malloc(sizeof(int)*mid);
		int* b1 = (int*)malloc(sizeof(int)*(sizeB - mid));
		
		for(i=0;i<mid;i++){
			b0[i] = b[i];
		}
		for(i=0;i<sizeB - mid;i++){
			b1[i] = b[mid+i];
		}

		int z2_size = 0;
		int z0_size = 0;
		int* z2 = karatsuba(a1,sizeA - mid, b1, sizeB - mid, &z2_size);
		int* z0 = karatsuba(a0,mid, b0, mid, &z0_size);

		int a0_size = 0;
		int b0_size = 0;
		a0 = add(a0,mid, a1,sizeA - mid, 0, &a0_size);
		b0 = add(b0,mid,  b1,sizeB - mid, 0, &b0_size);

		int z1_size=0;
		int* z1 = karatsuba(a0,a0_size, b0, b0_size, &z1_size);

		z1 = sub(z1, z1_size, z0, z0_size, &z1_size);
		z1 = sub(z1, z1_size, z2, z2_size, &z1_size);


		ret = add(ret, 0, z0, z0_size, 0, &ret_size);
		ret = add(ret, ret_size, z1, z1_size, mid, &ret_size);
		ret = add(ret, ret_size, z2, z2_size, mid + mid, &ret_size);
	}else{
		int z3_size=0;
		int z4_size=0;
		int* z3 = karatsuba(a0,mid, b, sizeB, &z3_size);
		int* z4 = karatsuba(a1,sizeA-mid, b, sizeB, &z4_size);

		ret = add(ret, 0, z3, z3_size, 0, &ret_size);
		ret = add(ret, ret_size, z4, z4_size, mid, &ret_size);
	}
	
	*resultSize = ret_size;
	return ret;
}


int main(int argc, char const *argv[])
{
	//54321*54321
	// int a[] = {1,2,3,4,5};
	// int b[] = {1,2,3,4,5};

	// int size = 0, i=0;
	// int* result = big_multiply(a, 5, b, 5, &size);

	// for(i=size-1;i>=0;i--){
	// 	printf("%d", result[i]);
	// }
	// printf("\n");

	// free(result);

	return 0;
}
