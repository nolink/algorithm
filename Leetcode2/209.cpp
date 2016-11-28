class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int i=0, j=0, sum = 0, ret = INT_MAX;
        while(j<nums.size()){
            sum += nums[j++];
            while(sum >= s){
                ret = min(ret, j-i);
                sum -= nums[i++];
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};
