class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0, len = s.length();
        while(len > 0 && isspace(s[len-1])) len--;
        while(len > 0){
            if(isspace(s[len-1])) break;
            len--;
            ret++;
        }
        return ret;
    }
};
