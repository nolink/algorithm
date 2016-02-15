char* countAndSay(int n) {
    char* result;
    if(n == 1){
        result = (char*)malloc(sizeof(char)*2);
        result[0] = '1';
        result[1] = '\0';
        return result;
    }
    
    char* str = countAndSay(n-1);
    int len = strlen(str);
    
    result = (char*)malloc(sizeof(char)*(len*2+1));
    
    int count = 0;
    int i = 0;
    int j = 0;
    char temp = '\0';
    for(;i<len;i++){
        if(temp != '\0' && str[i] != temp){
            result[j++] = count + '0';
            result[j++] = temp;
            count = 0;
        }
        temp = str[i];
        count++;
    }
    
    if(temp != '\0'){
        result[j++] = count + '0';
        result[j++] = temp;
    }
    
    result[j] = '\0';
    
    free(str);
    return result;
}