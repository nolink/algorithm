class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int n = triangle.size();
        vector<int> dp = triangle[n-1];
        vector<int> aux = dp;
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                dp[j] = triangle[i][j] + min(aux[j], aux[j+1]);
            }
            aux = dp;
        }
        return dp[0];
    }
};
