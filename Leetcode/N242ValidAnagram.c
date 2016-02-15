bool isAnagram(char* s, char* t) {
       int s_count[26];
    int t_count[26];
    
    int i=0;
    for(;i<26;i++){
        s_count[i]=0;
        t_count[i]=0;
    }
    
    while(s){
        char s_c = *s;
        if(s_c == '\0'){
            break;
        }
        s_count[s_c - 'a']++;
        s++;
    }
    
    while(t){
        char s_t = *t;
        if(s_t == '\0'){
            break;
        }
        t_count[s_t - 'a']++;
        t++;
    }
    
    i=0;
    for(;i<26;i++){
        if(s_count[i] != t_count[i]){
            return 0;
        }
    }
    
    return 1;
    
}