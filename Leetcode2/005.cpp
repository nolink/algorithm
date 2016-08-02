class Solution {
public:
    string expandPalindrome(string s, int n, int i, int j){
        while(i >= 0 && j < n && s[i] == s[j]){
            i--;
            j++;
        }
        return s.substr(i+1, j-i-1);
    }
    string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1) return s;
        string ret = "";
        for(int i=0;i<n-1;i++){
            string p1 = expandPalindrome(s, n, i, i);
            if(p1.length() > ret.length()) ret = p1;
            string p2 = expandPalindrome(s, n, i, i+1);
            if(p2.length() > ret.length()) ret = p2;
        }
        return ret;
    }
};
