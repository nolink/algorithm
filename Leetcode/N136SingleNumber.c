int singleNumber(int* nums, int numsSize) {
    
    if(NULL == nums || numsSize <= 0){
        return -1;
    }
    
    int result = nums[0];
    
    int i = 1;
    for(;i<numsSize;i++){
        result ^= nums[i];
    }
    
    return result;
    
}