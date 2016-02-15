
#include <stdio.h>

int main(int argc, char *argv[]){

	int to_be_sort[] = {3,2,5,1,6};

	int i = 0;
	int len = sizeof(to_be_sort) / sizeof(to_be_sort[0]);
	
	for(;i<len;i++){
		int j=0;
		for(;j<i;j++){
			if(to_be_sort[i] < to_be_sort[j]){
				int temp = to_be_sort[j];
				to_be_sort[j] = to_be_sort[i];
				to_be_sort[i] = temp;
			}
		}
	}

	int k=0;
	for(;k<len;k++){
		printf("%d\n", to_be_sort[k]);
	}
	return 0;
}
