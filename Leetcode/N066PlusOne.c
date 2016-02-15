/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* result;
    if(NULL == digits || digitsSize <= 0){
        result = (int*)malloc(sizeof(int));
        result[0] = 1;
        *returnSize = 1;
        return result;
    }
    
    int allocate = 1;
    int minus = 0;
    int i = 0;
    for(i=digitsSize-1;i>=0;i--){
        if(digits[i] < 9){
            allocate = 0;
            minus = 1;
            break;
        }
    }
    
    *returnSize = digitsSize + allocate;
    result = (int*)malloc(sizeof(int)*(*returnSize));
    bool add = 1;
    for(i=digitsSize-minus;i>=allocate;i--){
    	if(add == 0){
    		result[i] = digits[i-allocate];
    	}
        else if(digits[i-allocate] == 9){
            result[i] = 0;
            add = 1;
        }else{
            result[i] = digits[i-allocate] + 1;
            add = 0;
        }
    }
    
    if(allocate == 1){
        result[0] = 1;
    }
    
    return result;
    
}