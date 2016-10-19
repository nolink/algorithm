class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ret = INT_MIN, aux = 0;
        for(auto num : nums){
            aux += num;
            if(aux > ret) ret = aux;
            if(aux < 0) aux = 0;
        }
        return ret;
    }
};
