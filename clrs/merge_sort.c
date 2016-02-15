
#include <stdio.h>

void merge(int a[], int low, int mid, int high){

	printf("%d:%d:%d\n", low, mid, high);
	
	int left_count = mid - low + 1 + 1;
	int right_count = high - mid + 1;

	int left[left_count];
	int right[right_count];

	int left_i=0;
	int i = low;
	for(;i<=mid;i++){
		left[left_i++] = a[i];
	}
	left[left_i] = 1048576;

	int right_i = 0;
	int j=mid+1;
	for(;j<=high;j++){
		right[right_i++] = a[j];
	}
	right[right_i] = 1048576;

	int loop_i=0;
	int loop_j=0;
	int k=low;
	for(;k<=high;k++){
		if(left[loop_i] >= right[loop_j]){
			a[k] = right[loop_j];
			loop_j++;
		}else{
			a[k]=left[loop_i];
			loop_i++;
		}
	}

}

void split_and_sort(int a[], int low, int high){
	if(high > low){
		int mid = (high + low)/2;
		split_and_sort(a, low, mid);
		split_and_sort(a, mid+1, high);
		merge(a, low, mid, high);
	}
}

int main(int argc, char const *argv[]){
	
	int to_be_sort[] = {2,3,1,6,4,7,9};

	split_and_sort(to_be_sort, 0, 6);

	int i=0;
	for(;i<7;i++){
		printf("%d\n", to_be_sort[i]);
	}

	return 0;
}
