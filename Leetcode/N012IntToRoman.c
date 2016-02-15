int fill(char* data, int index, int real, int base){
    
    char generic, mid, next;
    
    switch(base){
        case 1:
            generic='I';
            mid = 'V';
            next = 'X';
            break;
        case 10:
            generic = 'X';
            mid = 'L';
            next = 'C';
            break;
        case 100:
            generic = 'C';
            mid = 'D';
            next = 'M';
            break;
    }
    
    if(real == 4){
        data[index++]=generic;
        data[index++]=mid;
    }else if(real <= 3){
        while(real > 0){
            data[index++]=generic;
            real--;
        }
    }else if(real == 9){
        data[index++]=generic;
        data[index++]=next;
    }else{
        data[index++] = mid;
        while(real > 5){
            data[index++]=generic;
            real--;
        }
    }
    return index;
}

char* intToRoman(int num) {
    
    if(num < 1 || num > 3999){
        return NULL;
    }
    
    char* result = (char *)malloc(sizeof(char)*16);
    
    int i = 0;
    
    int digit = num % 10;
    int ten = (num / 10) % 10;
    int hundred = (num / 100) % 10;
    int thousand = num / 1000;
    
    while(thousand > 0){
        result[i++] = 'M';
        thousand--;
    }
    
    i = fill(result, i, hundred, 100);
    i = fill(result, i, ten, 10);
    i = fill(result, i, digit, 1);

    result[i] = '\0';
    
    return result;
}