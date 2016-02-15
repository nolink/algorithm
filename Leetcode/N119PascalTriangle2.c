int* getRow(int rowIndex, int* returnSize) {

    int *a = (int *)malloc((rowIndex+2)*sizeof(int));
    *returnSize = rowIndex  + 1;
    
    int i=0;
    for(;i<rowIndex+2;i++){
        a[i] = 0;
    }
    
    int temp1 = 0;
    int temp2 = 0;
    
    a[0]=1;
    a[1]=1;
    
    i = 2;
    for(;i<=rowIndex;i++){
        temp1=a[0];
        temp2=a[1];
        int j = 1;
        for(;j<=i;j++){
            a[j]=temp1+temp2;
            temp1=temp2;
            temp2=a[j+1];
        }
        a[i]=1;
    }
    
    
    
    return a;
} 