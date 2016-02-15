int removeElement(int* nums, int numsSize, int val) {
    
    if(NULL == nums || numsSize <= 0){
        return 0;
    }
    
    int i = 0;
    int replace = 0;
    for(i=0;i<numsSize;i++){
        if(val != nums[i]){
            nums[replace] = nums[i];
            replace++;
        }
    }
    
    return replace;
    
}