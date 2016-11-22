class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int n = nums.size(), idx = 0;
        if(n > 0){
            for(int i=1;i<n;i++){
                if(nums[i] != nums[i-1] + 1){
                    ret.push_back(to_string(nums[idx]) + (idx == i-1 ? "" : "->"+to_string(nums[i-1])));
                    idx = i;
                }
            }
            ret.push_back(to_string(nums[idx]) + (idx == n-1 ? "" : "->"+to_string(nums[n-1])));
        }
        return ret;
    }
};
