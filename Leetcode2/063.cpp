class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid.begin()->empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid.begin()->size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=m-1;i>=0;i--){
            if(obstacleGrid[i][n-1] == 1) break;
            dp[i][n-1] = 1;
        }
        for(int j=n-1;j>=0;j--){
            if(obstacleGrid[m-1][j] == 1) break;
            dp[m-1][j] = 1;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
