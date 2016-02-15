/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    
    if(numsSize <= 0){
        *returnSize = 0;
        return NULL;
    }
    
    char** result;
    
    if(numsSize == 1){
        *returnSize = 1;
        result = (char**)malloc(1);
        result[0] = (char*)malloc(100);
        sprintf(result[0],"%d", nums[0]);
        return result;
    }
    
    int size = 0;
    
    result = (char**)malloc(sizeof(char*)*numsSize);
    
    int i;
    int start=nums[0];
    for(i=1;i<numsSize;i++){
        if(nums[i] - nums[i-1] != 1){
            if(start == nums[i-1]){
                result[size] = (char*)malloc(100);
                sprintf(result[size++],"%d", start);
            }else{
                result[size] = (char*)malloc(100);
                sprintf(result[size++], "%d->%d", start, nums[i-1]);
            }
            start=nums[i];
        }
    }
    
    if(start == nums[i-1]){
        result[size] = (char*)malloc(100);
        sprintf(result[size++],"%d", start);
    }else{
        result[size] = (char*)malloc(100);
        sprintf(result[size++], "%d->%d", start, nums[i-1]);
    }
    
    *returnSize=size;
    
    return result;
    
}