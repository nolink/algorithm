class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0, n = s.length(), i = 0, j = 0, aux = 0;
        if(n <= 1) return n; 
        unordered_map<char, int> us;
        while(i < n){
            bool exist = us.count(s[i]) > 0;
            if(i + 1 == n) return max(ret, exist ? i - j : i-j+1);
            if(exist){
                ret = max(ret, i - j);
                //jump
                aux = us[s[i]] + 1;
                for(;j < aux;j++){
                    us.erase(s[j]);
                }
            }
            us[s[i]] = i;
            i++;
        }
        return ret;
    }
};
