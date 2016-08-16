class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0, maxLeft = 0, maxRight = 0;
        for(int i=0, j = height.size() - 1;i<=j;){
            if(height[i] <= height[j]){
                if(height[i] <= maxLeft){
                    ret += maxLeft - height[i];
                }else{
                    maxLeft = height[i];
                }
                i++;
            }else{
                if(height[j] <= maxRight){
                    ret += maxRight - height[j];
                }else{
                    maxRight = height[j];
                }
                j--;
            }
        }
        return ret;
    }
};
