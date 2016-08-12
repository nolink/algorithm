class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), ret = 0;
        vector<int> dp(n, 0);
        for(int i=n-2;i>=0;i--){
            int j = i+dp[i+1]+1;
            if(s[i] == '(' && s[j] == ')'){
                dp[i] = dp[i+1] + 2 + (j + 1 < n ? dp[j+1] : 0);
                ret = max(ret, dp[i]);
            }
        }
        return ret;
    }
};
