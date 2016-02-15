int rob(int* nums, int numsSize) {
    
    if(numsSize == 0){
        return 0;
    }
    
    int yes[numsSize];
    int no[numsSize];
    
    no[0]=0;
    yes[0]=nums[0];
    
    int i=1;
    for(;i<numsSize;i++){
        no[i] = yes[i-1] > no[i-1] ? yes[i-1] : no[i-1];
        yes[i] = nums[i] + no[i-1];
    }
    
    return yes[i-1] > no[i-1] ? yes[i-1] : no[i-1];
    
}