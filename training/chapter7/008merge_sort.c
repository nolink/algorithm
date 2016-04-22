
#include <stdio.h>
#include <stdlib.h>

void merge(int* array, int from_idx, int mid, int to_idx){

	int* tmp = (int*)malloc(sizeof(int)*(to_idx - from_idx + 1));

	int i=0,j=0,k=0;

	for(i=from_idx,j=mid+1;i<=mid && j<=to_idx;){
		if(array[i] < array[j]){
			tmp[k++] = array[i++];
		}else{
			tmp[k++] = array[j++];
		}
	}

	if(i<=mid){
		for(;i<=mid;i++){
			tmp[k++] = array[i];
		}
	}

	if(j<=to_idx){
		for(;j<=to_idx;j++){
			tmp[k++] = array[j];
		}
	}

	for(i=0;i<k;i++){
		array[from_idx+i] = tmp[i];
	}

	free(tmp);

}

void sort(int* array, int from_idx, int to_idx){

	int mid = 0;
	if(from_idx < to_idx){
		mid = (from_idx + to_idx) / 2;
		sort(array, from_idx, mid);
		sort(array, mid+1, to_idx);

		merge(array, from_idx, mid, to_idx);
	}

}


int main(int argc, char const *argv[])
{
	
	int i=0;
	int array[] = {3,4,2,1,5,7,9,6};
	sort(array, 0, 7);

	for(i=0;i<8;i++){
		printf("%d ", array[i]);
	}

	return 0;
}