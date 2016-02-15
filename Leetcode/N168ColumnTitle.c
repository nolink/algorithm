char* convertToTitle(int n) {
    
    char* result = NULL;
    int i = 1;
    int j = 0;
    
    while(n > 0){
        result = (char*)realloc(result, i + 1);
        for(j=i-1;j>0;j--){
            result[j] = result[j-1];
        }
        result[0] = ((n - 1) % 26) + 'A';
        n = (n - 1) / 26;
        i++;
    }
    
    result[i-1] = '\0';
    
    return result;
}