char* convert(char* s, int numRows) {

    int n = strlen(s);

    char* t = (char *)malloc(n+1);
    
    if(numRows<=1 || n<numRows) {
        strcpy(t, s); 
        return t;
    }else if (n<= 0) { 
        t[0] = '\0';
        return t;
    }
    
    int i=0;
    int j=0;
    int k=0;
    for(;i<numRows;i++){
        for(j=i;j<n;j+=(numRows-1)*2){
            t[k++] = s[j];
            if(i>0 && i< numRows-1 && (j+2*(numRows-i-1)) < n){
                t[k++]=s[j+2*(numRows-i-1)];
            }
        }
    }

    t[k] = '\0';
    
    return t;
}