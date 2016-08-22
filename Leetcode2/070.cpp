class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        vector<int> dp(n + 1, 1);
        for(int i=n-2;i>=0;i--){
            dp[i] = dp[i + 2] + dp[i + 1];
        }
        return dp[0];
    }
};
