class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.length(), tlen = t.length();
        if(slen < tlen) return 0;
        vector<vector<int>> dp(tlen+1, vector<int>(slen+1, 0));
        for(int j=0;j<=slen;j++) dp[0][j] = 1;
        for(int i=0;i<tlen;i++){
            for(int j=0;j<slen;j++){
                dp[i+1][j+1] = (t[i] == s[j] ? dp[i][j] : 0) + dp[i+1][j];
            }
        }
        return dp[tlen][slen];
    }
};
