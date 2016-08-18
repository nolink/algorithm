class Solution {
public:
    static inline int aux(vector<int>& nums, int i, int j){
        int yes = 0, no = 0, t = 0;
        while(i < j){
            t = yes;
            yes = nums[i] + no;
            no = max(no, t);
            i++;
        }
        return max(yes, no);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        return max(aux(nums, 0, n - 1), aux(nums, 1, n));
    }
};