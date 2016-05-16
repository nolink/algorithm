

#include <stdio.h>


int max_area(int* heights, int size){

	int i=0,j=0,max=0;

	for(i=0;i<size;i++){
		int minHeight = heights[i];
		for(j=i;j<size;j++){
			if(heights[j] < minHeight){
				minHeight = heights[j];
			}
			int candidate = (j-i+1)*minHeight;
			if(candidate > max){
				max = candidate;
			}
		}
	}

    return max;

}

int max_area_2(int* heights, int size, int from, int to){

	if(from == to){
		return heights[from];
	}

	int mid = (from+to)/2;

	int max = max_area_2(heights, size, from, mid);
	int max_right = max_area_2(heights, size, mid+1, to);

	if(max_right > max){
		max = max_right;
	}

	int left = mid, right = mid+1;
	int minHeight = heights[right] < heights[left] ? heights[right] : heights[left];
	int candidate = minHeight*2;
	if(candidate > max){
		max = candidate;
	}

	while(left > from || right < to){

		if(right < to && (left == from ||  heights[left-1] < heights[right+1])){
			right++;
			if(heights[right] < minHeight){
				minHeight = heights[right];
			}
		}else{
			left--;
			if(heights[left] < minHeight){
				minHeight = heights[left];
			}
		}
		candidate = minHeight * (right - left+1);
		if(candidate > max){
			max = candidate;
		}
	}

	return max;
}

int main(int argc, char const *argv[])
{
	int case1[] = {7,1,5,9,6,7,3};
	int case2[] = {1,4,4,4,4,1,1};
	int case3[] = {1,8,2,2};

	printf("%d\n", max_area(case1, 7));
	printf("%d\n", max_area(case2, 7));
	printf("%d\n", max_area(case3, 4));

	printf("%d\n", max_area_2(case1, 7, 0, 6));
	printf("%d\n", max_area_2(case2, 7, 0, 6));
	printf("%d\n", max_area_2(case3, 4, 0, 3));

	return 0;
}
