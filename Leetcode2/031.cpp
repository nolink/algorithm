class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        int i = n;
        while(--i > 0){
            if(nums[i] > nums[i-1]){
                int j = n;
                //number in [i, n) are in descending order
                //so find the first j in [i, n) that is greater than nums[i-1]
                //swap i-1 and j and reverse the order of [i, n) will get next permutation
                while(nums[--j] <= nums[i-1]);
                swap(nums[i-1], nums[j]);
                break;
            }
        }
        reverse(nums.begin() + i, nums.end());
    }
};
