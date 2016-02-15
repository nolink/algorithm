int countPrimes(int n) {
    
    bool prime[n];
    
    int i=2;
    
    for(;i<n;i++){
        prime[i] = 1;
    }
    
    int j=0;
    for(i=2;i*i<n;i++){
        if(prime[i] == 0){
            continue;
        }
        for(j=i*i;j<n;j+=i){
            prime[j]=0;
        }
    }
    
    int count = 0;
    for(i=2;i<n;i++){
        if(prime[i]) count++;
    }
    
    return count;
    
}