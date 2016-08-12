class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int n = nums.size(), i = 0, j = n - 1;
        if(target == nums[i]){
            return i;
        }else if(target == nums[j]){
            return j;
        }else if(target < nums[i] && target > nums[j]){
            return -1;
        }else if(target < nums[i] && target < nums[j]){
            while(i < j && nums[i] < nums[++i]);
            j--;
        }else if(target > nums[i] && target > nums[j]){
            while(j > i && nums[j] > nums[--j]);
            i++;
        }
        auto it = lower_bound(nums.begin() + i, nums.begin() + j, target);
        return (it == nums.end() || *it != target) ? -1 : it - nums.begin();
    }
};
