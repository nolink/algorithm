char* longestCommonPrefix(char** strs, int strsSize) {
    
    if(NULL == strs || strsSize <= 0){
        return "";
    }
    
    if(strsSize == 1){
        return strs[0];
    }
    
    char* shortest = strs[0];
    int shortest_len = strlen(shortest);
    int temp_len = 0;
    int temp_idx = 0;
    int i=1;
    int j=0;
    int k=0;
    for(;i<strsSize;i++){
        temp_len = strlen(strs[i]);
        if(temp_len < shortest_len){
            shortest_len = temp_len;
            shortest = strs[i];
            temp_idx = i;
        }
    }
    
    char* result = (char*)malloc(sizeof(char)*shortest_len);
    
    for(;j<shortest_len;j++){
        for(i=0;i<strsSize;i++){
            if(i != temp_idx){
                if(strs[i][j] != shortest[j]){
                    result[k]='\0';
                    return result;
                }
            }
        }
        result[k++]=shortest[j];
    }
    
    result[k]='\0';
    return result;
    
}