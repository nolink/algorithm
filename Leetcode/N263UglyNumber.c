bool isUgly(int num) {
    
    if(num <= 0){
        return 0;
    }
    
    int magic = 0;
    
    while((num % 2 == 0 && (magic = 2) == 2) 
        || (num % 3 == 0 && (magic = 3) == 3) 
        || (num % 5 == 0 && (magic = 5) == 5)){
        num /= magic;
    }
    
    return num == 1;
    
}