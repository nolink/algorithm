class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 1, steps = 0;
        while(j < n){
            for(int k = min(nums[i] + i + 1, n);j<k;j++){
                if(nums[j] + j > nums[i] + i){
                    i = j;
                }
            }
            steps++;
        }
        return steps;
    }
};
