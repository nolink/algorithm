class Solution {
public:
    static inline int skip_start(vector<int>& nums, int start, int end){
        int n = nums[start];
        while(start < end && n == nums[start]) ++start;
        return start;
    }
    static inline int skip_end(vector<int>& nums, int start, int end){
        int n = nums[end];
        while(start < end && n == nums[end]) --end;
        return end;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        if(n < 3) return ret;
        sort(nums.begin(), nums.end());
        for(int i=0;i<=n-3;i = skip_start(nums, i, n-1)){
            int a = nums[i];
            for(int start = i + 1, end = n - 1;start < end;){
                int b = nums[start], c = nums[end];
                if(a + b + c == 0){
                    ret.push_back({a, b, c});
                    start = skip_start(nums, start, end);
                }    
                else if(a + b + c < 0){
                    start = skip_start(nums, start, end);
                }
                else{
                    end = skip_end(nums, start, end);
                }
            }
        }
        return ret;
    }
};
