class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid.begin()->empty()) return 0;
        int m = grid.size(), n = grid.begin()->size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = grid[m-1][n-1];
        for(int i=n-2;i>=0;i--) dp[m-1][i] = grid[m-1][i] + dp[m-1][i+1];
        for(int j=m-2;j>=0;j--) dp[j][n-1] = grid[j][n-1] + dp[j+1][n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[j][i] = grid[j][i] + min(dp[j+1][i], dp[j][i+1]);
            }
        }
        return dp[0][0];
    }
};
