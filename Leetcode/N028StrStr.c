void fill(char* needle, int* next, int n){
    
    int i = 0, j = -1;

    next[0] = -1;
    
    while (i != n - 1)
    {
        //这里注意，i==0的时候实际上求的是next[1]的值，以此类推
        if (j == -1 || needle[i] == needle[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
    
}

int strStr(char* haystack, char* needle) {
    
    if(NULL == haystack || NULL == needle){
        return -1;
    }
    
    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    
    if(hlen < nlen){
        return -1;
    }
    if(nlen == 0 || (hlen == 0 && nlen == 0)){
        return 0;
    }
    
    int next[nlen];
    int i = 0;
    int j = 0;
    int index = -1;
    fill(needle, next, nlen);
    
    while(j < hlen && i < nlen)
    {
        if (i == -1 || needle[i] == haystack[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = next[i];
        }
    }

    return i == nlen ? j - i: -1;
}