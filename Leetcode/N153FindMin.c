int findMin(int* nums, int numsSize) {
    if(NULL == nums || numsSize <= 0){
        return -1;
    }
    int i = 1;
    int min = nums[0];
    for(;i<numsSize;i++){
        if(nums[i] < min){
            min = nums[i];
        }
    }
    return min;
}