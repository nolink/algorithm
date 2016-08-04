class Solution {
public:
    int skip_start(vector<int>& nums, int start, int end){
        int n = nums[start];
        while(start < end && n == nums[start]) ++start;
        return start;
    }
    int skip_end(vector<int>& nums, int start, int end){
        int n = nums[end];
        while(start < end && n == nums[end]) --end;
        return end;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int n = nums.size();
        if(n < 4) return ret;
        sort(nums.begin(), nums.end());
        for(int i=0;i<=n-4;i=skip_start(nums, i, n-3)){
            int a = nums[i];
            int aux = target - a;
            for(int j=i+1;j<=n-3;j=skip_start(nums, j, n-2)){
                int b = nums[j];
                for(int start=j+1, end = n-1;start < end;){
                    int c = nums[start], d = nums[end], sum = b + c + d;
                    if(sum == aux){
                        ret.push_back({a, b, c, d});
                        start = skip_start(nums, start, end);
                    }else if(sum < aux){
                        start = skip_start(nums, start, end);
                    }else{
                        end = skip_end(nums, start, end);
                    }
                }
            }
        }
        return ret;
    }
};
