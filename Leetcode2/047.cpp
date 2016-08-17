class Solution {
public:
    void backtrack(vector<vector<int>>& ret, vector<int>& nums, int idx){
        if(idx == nums.size()){
            ret.push_back(nums);
            return;
        }
        for(int i = idx;i < nums.size();i++){
            if(i != idx && nums[i] == nums[idx]) continue;
            swap(nums[idx], nums[i]);
            backtrack(ret, nums, idx+1);
        }
        for (int i = nums.size() - 1; i > idx; --i) {
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        backtrack(ret, nums, 0);
        return ret;
    }
};
