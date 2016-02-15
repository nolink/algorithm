int lengthOfLastWord(char* s) {
    if(NULL == s){
        return 0;
    }
    
    int len = strlen(s);
    if(len <= 0){
        return 0;
    }
    
    char* prev = NULL;
    char* current = NULL;
    char* delim = " ";
    
    current = strtok(s, delim);
    if(NULL == current){
        return 0;
    }
    
    do{
        prev = current;
        current = strtok(NULL, delim);
    }while(NULL != current);
    
    return strlen(prev);
    
}