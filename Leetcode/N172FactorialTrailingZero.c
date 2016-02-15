int trailingZeroes(int n) {
    
    int x = n / 5;
    
    int temp = 0;
    
    do{
        temp += x;
        x = x / 5;
    }while(x != 0);
    
    return x + temp;
    
}