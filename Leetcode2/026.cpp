class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nlen = 1, n = nums.size();;
        if(n <= 1) return n;
        for(int i=1; i < nums.size();i++){
            if(nums[i] != nums[i-1]){
                nums[nlen++] = nums[i];
            }
        }
        return nlen;
    }
};
