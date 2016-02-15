
#include <stdio.h>

int partition(int array[], int start, int end){
	int pivot = array[start];
	int i=start+1;
	int j = start;
	for(;i<=end;i++){
		if(array[i] <= pivot){
			j++;
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	int temp = array[j];
	array[j] = pivot;
	array[start] = temp;
	return j;
}

void quick_sort(int array[], int start, int end){
	if(start < end){
		int sorted_pivot_idx = partition(array, start, end);
		quick_sort(array, start, sorted_pivot_idx-1);
		quick_sort(array, sorted_pivot_idx+1, end);
	}
}

int main(int argc, char const *argv[])
{
	int test[] = {6,7,3,8,4};

	quick_sort(test, 0, 4);

	int i=0;
	for(;i<5;i++){
		printf("%d\n", test[i]);
	}

	return 0;
}
