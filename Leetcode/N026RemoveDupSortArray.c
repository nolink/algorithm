int removeDuplicates(int* nums, int numsSize) {
    if(NULL == nums || numsSize <= 0){
        return 0;
    }
    
    int i = 0;
    int distinct = 1;
    int pivot = nums[0];
    for(i=1;i<numsSize;i++){
        if(nums[i] != pivot){
            pivot = nums[distinct] = nums[i];
            distinct++;
        }
    }
    
    return distinct;
}