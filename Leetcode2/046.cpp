class Solution {
public:
    void backtrack(vector<vector<int>>& ret, vector<int>& nums, int idx){
        if(idx >= nums.size()){
            ret.push_back(nums);
            return;
        }
        for(int i = idx;i < nums.size();i++){
            swap(nums[idx], nums[i]);
            backtrack(ret, nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        backtrack(ret, nums, 0);
        return ret;
    }
};
