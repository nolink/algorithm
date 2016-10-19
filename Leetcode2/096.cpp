class Solution {
public:
    int aux(int n, vector<int>& dp){
        if(n <= 2) return n;
        int& ret = dp[n];
        if(ret != -1) return ret;
        ret = 0;
        for(int i=0;i<n;i++){
            if(i == 0 || i == n - 1){
                ret += aux(n - 1, dp);
            }else{
                ret += aux(n - i - 1, dp) * aux(i, dp);
            }
        }
        return ret;
    }
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return aux(n, dp);
    }
};
