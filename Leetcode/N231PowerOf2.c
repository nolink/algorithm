bool isPowerOfTwo(int n) {
    
    if(n <= 0){
        return 0;
    }
    
    if(n == 1){
        return 1;
    }
    
    int shift = 0;
    int shifted = 0;
    
    do{
       shift++;
       shifted = n >> shift;
       
       if(n != (shifted << shift)){
           return 0;
       }
       
    }while(shifted > 1);
    
    return 1;
}