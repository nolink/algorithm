class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        if(s[n-1] != '0') dp[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            if(s[i] == '0') continue;
            if(s[i] >= '3' || (s[i] == '2' && s[i+1] >= '7')){
                dp[i] = dp[i+1];
            }else{
                dp[i] = dp[i+2] + dp[i+1];
            }
        }
        return dp[0];
    }
};
