/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {
    
     if(!columnSizes) return 0;
    if(!returnSize||numRows==0) return 0;

    int **result = (int **)malloc(sizeof(int *)*numRows);
    *columnSizes = (int *)malloc(sizeof(int)*numRows);

    *returnSize = 0;

    int i = 0;
    for(;i<numRows;i++){
        int *current = (int *)malloc(sizeof(int)*(i + 1));
        current[0]=1;
        current[i]=1;
        if(i > 1){
            int *prev = result[i-1];
            int j = 1;
            for(;j<i;j++){
                current[j] = prev[j-1]+prev[j];
            }
        }
        (*columnSizes)[i] = i + 1;
        result[i] = current;
        (*returnSize)++;
    }

    return result;
}