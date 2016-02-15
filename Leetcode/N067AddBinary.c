char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    
    char* result = (char*)malloc(sizeof(char)*(lenA > lenB ? lenA + 2 : lenB + 2));
    
    int len = 0;
    int i = 0;
    int j = 0;
    int carry = 0;
    int current = 0;
    int diff = 0;
    if(lenA > lenB){
        diff = lenA - lenB;
        for(i=lenB-1;i>=0;i--){
            current = (a[i+diff] - '0') + (b[i] - '0') + carry;
            carry = current / 2;
            result[len++] = (current % 2) + '0';
        }
        for(i=lenA-lenB-1;i>=0;i--){
            current = (a[i] - '0') + carry;
            carry = current / 2;
            result[len++] = (current % 2) + '0';
        }
    }else if(lenA < lenB){
        diff = lenB - lenA;
        for(i=lenA-1;i>=0;i--){
            current = (a[i] - '0') + (b[i+diff] - '0') + carry;
            carry = current / 2;
            result[len++] = (current % 2) + '0';
        }
        for(i=lenB-lenA-1;i>=0;i--){
            current = (b[i] - '0') + carry;
            carry = current / 2;
            result[len++] = (current % 2) + '0';
        }
    }else{
        for(i=lenA-1;i>=0;i--){
            current = (a[i] - '0') + (b[i] - '0') + carry;
            carry = current / 2;
            result[len++] = (current % 2) + '0';
        }
    }
    
    if(carry > 0){
        result[len++] = carry + '0';
    }
    
    char temp = '\0';
    for(i=0,j=len-1;i<j;i++,j--){
        temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
    result[len] = '\0';
    
    return result;
}