class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = -1, j = -1, n = nums.size();
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if(it != nums.end() && *it == target){
            j = i = it - nums.begin();  
            while(j + 1 < n){
                if(nums[j + 1] != nums[i]) break;
                j++;
            }
        }
        return {i, j};
    }
};
