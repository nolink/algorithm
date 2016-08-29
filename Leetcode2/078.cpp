class Solution {
public:
    void backtrack(vector<vector<int>>& ret, vector<int>& nums, int idx, vector<int>& chosen, int expect){
        if(expect == 0){
            ret.push_back(chosen);
            return;
        }
        for(int i=idx;i + expect <= nums.size();i++){
            chosen.push_back(nums[i]);
            backtrack(ret, nums, i + 1, chosen, expect - 1);
            chosen.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> chosen;
        ret.push_back(chosen);
        for(int i=1;i<=nums.size();i++){
            backtrack(ret, nums, 0, chosen, i);
        }
        return ret;
    }
};
