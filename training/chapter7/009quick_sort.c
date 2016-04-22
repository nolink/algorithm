

#include <stdio.h>


void sort(int* array, int from, int to){

	if(from >= to)
    {
        return ;
    }

	int pivot = array[from];

	int i=from,j=to;

	while(i<j){
		while(i<j && array[j] >= pivot) j--;
		array[i] = array[j];
		while(i<j && array[i] <= pivot) i++;
		array[j] = array[i];
	}

	array[i] = pivot;
	sort(array, from, i-1);
	sort(array, i+1, to);

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
