int titleToNumber(char* s) {
    
    int len = strlen(s);
    
    if(len <= 0){
        return 0;
    }
    
    int i = 0;
    int multip = 1;
    int result = 0;
    for(i=len-1;i>=0;i--){
        result += (s[i] - 'A' + 1)*multip;
        multip *= 26;
    }
    
    return result;
}