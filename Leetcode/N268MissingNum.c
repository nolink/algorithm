int missingNumber(int* nums, int numsSize) {
    
    long long total = numsSize*(numsSize + 1)/2;
    
    long long partial = 0;
    int i = 0;
    for(;i<numsSize;i++){
        partial += nums[i];
    }
    
    return (int)(total -partial );
    
}