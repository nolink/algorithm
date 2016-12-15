class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxProduct = nums[0], minProduct = nums[0], ret = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] >= 0){
                maxProduct = max(nums[i] * maxProduct, nums[i]);
                minProduct = min(nums[i]*minProduct, nums[i]);
            }else{
                int aux = maxProduct;
                maxProduct = max(minProduct * nums[i], nums[i]);
                minProduct = min(aux * nums[i], nums[i]);
            }
            ret = max(ret, maxProduct);
        }
        return ret;
    }
};
