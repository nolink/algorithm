bool isPalindrome(int x) {
    
    if(x < 0){
        return 0;
    }
    
    if(x ==0 || (x / 10) == 0){
        return 1;
    }
    
    int firstDivide = 1;
    int lastDivide = 1;
    
    while(firstDivide < 1000000000 && x >= firstDivide*10){
        firstDivide *= 10;
    }
    
    while(firstDivide >= lastDivide){
        if((x / lastDivide) % 10 != (x / firstDivide) % 10){
            return 0;
        }
        firstDivide /= 10;
        lastDivide *= 10;
    }
    
    return 1;
}