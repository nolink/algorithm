class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nlen = 0, n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] != val){
                nums[nlen++] = nums[i];
            }
        }
        return nlen;
    }
};
