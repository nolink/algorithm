class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return INT_MIN;
        int i = 0, j = nums.size() - 1;
        if(nums[i] > nums[j]){
            while(i < j && nums[i] < nums[i+1]) i++;
            if(i < j) i++;
        }
        return nums[i];
    }
};
