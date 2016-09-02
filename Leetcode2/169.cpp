class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], count = 0;
        for(auto num : nums){
            if(count == 0){
                count = 1;
                candidate = num;
            }else if(candidate == num){
                count++;
            }else{
                count--;
            }
        }
        return candidate;
    }
};
