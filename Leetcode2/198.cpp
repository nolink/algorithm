class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int yes = nums[0], no = 0, aux = 0;
        for(int i=1;i<nums.size();i++){
            aux = yes;
            yes = nums[i] + no;
            if(aux > no) no = aux;
        }
        return yes > no ? yes : no;
    }
};
