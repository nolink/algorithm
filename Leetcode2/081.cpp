class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while(i < j){
            if(target == nums[i] || target == nums[j]) return true;
            if(target < nums[i] && target > nums[j]) return false;
            if(target < nums[i] && target < nums[j]){
                while(i < j && nums[i] <= nums[i+1]) i++;
                if(i < j) i++;
            }else if(target > nums[i] && target < nums[j]){
                auto it = lower_bound(nums.begin() + i, nums.begin() + j, target);
                return it != nums.end() && *it == target;
            }else{
                while(i < j && nums[j-1] <= nums[j]) j--;
                if(i < j) j--;
            }
        }
        return i == j && nums[i] == target;
    }
};
