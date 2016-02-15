
#include <stdio.h>


void heapify(int array[], int heap_size, int idx){

	int largest_idx = -1;
	int left = 2*(idx) + 1;
	int right = 2*(idx+1);
	if(left <= heap_size && array[left] > array[idx]){
		largest_idx = left;
	}else{
		largest_idx = idx;
	}
	if(right <= heap_size && array[right] > array[largest_idx]){
		largest_idx = right;
	}
	if(largest_idx != idx){
		//This is important
		int temp = array[largest_idx];
		array[largest_idx] = array[idx];
		array[idx] = temp;
		heapify(array, heap_size, largest_idx);
	}
}


int build_max_heap(int array[], int array_size){
	int heap_size = array_size - 1;

	int non_leaf_idx = heap_size / 2;

	for(;non_leaf_idx >= 0;non_leaf_idx--){
		heapify(array, heap_size, non_leaf_idx);
	}
	return heap_size;
}


void heap_sort(int array[], int array_size){

	int heap_size = build_max_heap(array, array_size);

	int loop_v = heap_size;

	for(;loop_v>=1;loop_v--){
		int temp = array[0];
		array[0] = array[loop_v];
		array[loop_v] = temp;

		heap_size--;
		heapify(array, heap_size, 0);
	}

}


int main(int argc, char const *argv[])
{
	
	int array[] = {3,2,5,1,6};

	heap_sort(array, 5);

	int k=0;
	for(;k<5;k++){
		printf("%d\n", array[k]);
	}

	return 0;
}
