class Solution {
public:
    int titleToNumber(string s) {
        int mul = 1, ret = 0;
        for(int i = s.length() - 1;i >=0;i--){
            int c = s[i] - 'A' + 1;
            ret += c * mul;
            mul *= 26;
        }
        return ret;
    }
};
