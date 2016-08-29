class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        int ret = 1, cmp = nums[0], cnt = 1;
        for(int i=1;i<n;i++){
            if(nums[i] != cmp){
                nums[ret++] = cmp = nums[i];
                cnt = 1;
            }else if(cnt < 2){
                nums[ret++] = nums[i];
                cnt++;
            }else if(nums[i] != cmp && cnt >= 2){
                cnt = 0;
            }
        }
        return ret;
    }
};
