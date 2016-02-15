#include <stdio.h>
#include <stdlib.h>

void my_qsort(int* nums, int fromIdx, int toIdx){
    
    if(fromIdx >= toIdx){
        return;
    }
    
    int key = nums[fromIdx];
    int i=fromIdx;
    int j=toIdx;
    
    while(i < j){
        while(i < j && nums[j] > key){
            j--;
        }
        nums[i] = nums[j];
        while(i < j && nums[i] < key){
            i++;
        }
        nums[j] = nums[i];
    }
    nums[i] = key;
    my_qsort(nums, fromIdx, i-1);
    my_qsort(nums, i+1, toIdx);
}

int getLastLessThanIdx(int* nums, int fromIdx, int toIdx, int target){
    if(fromIdx > toIdx){
        return -1;
    }
    if(fromIdx == toIdx){
        return nums[fromIdx] >= target ? -1 : fromIdx;
    }
    
    int mid = (fromIdx + toIdx) / 2;
    
    if(nums[mid] < target){
        return nums[mid+1] >= target ? mid : getLastLessThanIdx(nums, mid+1, toIdx, target) ;
    }else{
        return getLastLessThanIdx(nums, fromIdx, mid-1, target);
    }
}

int main(int argc, char const *argv[])
{
    int* test = (int*)malloc(sizeof(int)*3);

    test[0] = 3;
    test[1] = 2;
    test[2] = 4;

    my_qsort(test, 0, 2);

    printf("%d\n", getLastLessThanIdx(test,0,2,6));

    return 0;
}