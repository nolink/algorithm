class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), i = 0, j = n-1, ret = 0;
        while(i<j){
            int left = height[i], right = height[j];
            ret = max(ret, min(left, right)*(j-i));
            if(left < right){
                while(height[i] <= left) i++;
            }else{
                while(height[j] <= right) j--;
            }
        }
        return ret;
    }
};
