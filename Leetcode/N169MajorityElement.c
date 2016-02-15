int majorityElement(int* nums, int numsSize) {
    int candidate = 0;
    int repeatTimes = 0;
    int i = 0;
    for(;i<numsSize;i++){
        if(repeatTimes == 0){
            candidate = nums[i];
            repeatTimes = 1;
        }else{
            if(candidate == nums[i]){
                repeatTimes++;
            }else{
                repeatTimes--;
            }
        }
    }
    return candidate;
}
