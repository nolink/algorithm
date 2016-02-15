void rotate(int* nums, int numsSize, int k) {
    
    if(numsSize <= 0 || k <= 0 || numsSize == k){
        return;
    }
    
    int extra = k % numsSize;
    int reverse[extra];
    int i=0;
    int j=0;
    
    for(i=numsSize-extra;i<numsSize;i++){
        reverse[j++] = nums[i];
    }
    
    for(i=numsSize-extra-1;i>=0;i--){
        nums[i+extra] = nums[i];
    }
    
    for(i=0;i<j;i++){
        nums[i]=reverse[i];
    }
    
}