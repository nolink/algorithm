class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), ret = 0;
        vector<int> dp(n, 0);
        for(int i=n-2;i>=0;i--){
            if(s[i] == '(' && s[i+dp[i+1]+1] == ')'){
                int j = i + dp[i+1] + 2;
                dp[i] = dp[i+1] + 2 + (j < n && s[j] == '(' ? dp[j] : 0);
                ret = max(ret, dp[i]);
            }
        }
        return ret;
    }
};
