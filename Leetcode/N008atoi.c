int myAtoi(char* str) {
    
    while(1){
        if(NULL == str){
            return 0;
        }
        char v = *str;
        if(v == ' ' || v == '\t' || v == '\n' || v == '\r'){
            str++;
        }else{
            break;
        }
    }
    
    int positive = 1;
    char* start=NULL;
    if((*str) == '+' || (*str) == '-'){
        if((*str) == '-'){
            positive = 0;
        }
        start = ++str;
    }else{
        start = str;
    }
    
    if(NULL == start){
        return 0;
    }
    
    while(1){
        char v = *str;
        if(v >= '0' && v <= '9'){
            str++;
        }else{
            break;
        }
    }
    
    if(start == str){
        return 0;
    }
    
    int count = str - start;
    int array[count];
    int i = 0;
    while(start < str){
        array[i++] = (*start) - '0';
        start++;
    }
    
    int k = count - 1;
    int result = 0;
    int j = 1;

    if(count > 10){
        return (positive == 1) ? 2147483647 : -2147483648;
    }

    while(k>=0){
        if((positive == 1 && result > 147483647 && array[k] >= 2) 
            || (positive == 0 && result > 147483648 && array[k] >= 2) ){
            return (positive == 1) ? 2147483647 : -2147483648;
        }
        result += array[k]*j; 
        j *= 10;
        k--;
    }
    
    if(positive == 0){
        result = -result;
    }
    
    return result;
    
}