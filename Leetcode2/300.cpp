class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // if(n <= 1) return n;
        // int ret = 1;
        // vector<int> dp(n, 1);
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        //         ret = max(ret, dp[i]);
        //     }
        // }
        // return ret;
        vector<int> dp;
        for(auto num : nums){
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if(it == dp.end()){
                dp.push_back(num);
            }else{
                *it = num;
            }
        }
        return dp.size();
    }
};
