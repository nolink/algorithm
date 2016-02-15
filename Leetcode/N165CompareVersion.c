int compareVersion(char* version1, char* version2) {
    
    int value1=0;
    int value2=0;
    
    while(1){
        value1=0;
        value2=0;
        while((*version1) != '\0' && (*version1) != '.'){
            value1 = (value1 * 10) + (*version1) - '0';
            version1++;
        }
        
        while((*version2) != '\0' && (*version2) != '.'){
            value2 = (value2 * 10) + (*version2) - '0';
            version2++;
        }
        
        if(value1 != value2){
            return value1 > value2 ? 1 : -1;
        }
        
        if((*version1) == '\0' && (*version2) != '\0'){
            version2++;
        }else if((*version2) == '\0' && (*version1) != '\0'){
            version1++;
        }else if((*version1) == '\0' && (*version2) == '\0'){
            return 0;
        }else{
            version1++;
            version2++;
        }
        
    }
    
    
}