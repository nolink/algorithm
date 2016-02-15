int reverse(int x) {
    int count = 0;
    int left = x;
    while(left != 0){
        left = left / 10;
        count++;
    }
    
    int reverse[count];
    int i = 0;
    left = x;
    while(left != 0){
        reverse[i++] = left % 10;
        left = left / 10;
    }
    
    int result=0;
    int j=1;
    int k=i-1;

    int to_break = 0;
    if(count == 10 && (reverse[0] >= 3 || reverse[0] <= -3)){
        result = 0;
        to_break = 1;
    }

    if(to_break == 0){
        for(;k>=0;k--){
            result += reverse[k] * j;
            j = j*10;
            if((reverse[0] == 2 || reverse[0] == -2) && k == 1 
                && (result >= 147483647 || result <= -147483648)){
                result = 0;
                break;
            }
        }
    }
    
    return result;
}