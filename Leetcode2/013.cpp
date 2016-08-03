class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        for(int i=s.length()-1;i>=0;--i){
            switch(s[i]){
                case 'I':
                    ++ret;
                    break;
                case 'V': 
                case 'X': 
                    ret += s[i] == 'V' ? 5 : 10; 
                    if(i > 0 && s[i-1] == 'I'){
                        --ret;
                        --i;
                    } 
                    break;
                case 'L': 
                case 'C': 
                    ret += s[i] == 'L' ? 50 : 100; 
                    if(i > 0 && s[i-1] == 'X'){
                        ret-=10;
                        --i;
                    } 
                    break;
                case 'D': 
                case 'M': 
                    ret += s[i] == 'D' ? 500 : 1000; 
                    if(i > 0 && s[i-1] == 'C'){
                        ret-=100;
                        --i;
                    } 
                    break;
            }
        }
        return ret;
    }
};
