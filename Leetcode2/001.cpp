class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++){
            int left = target - nums[i];
            if(m.count(left) > 0){
                return vector<int>({i, m[left]});
            }
            m[nums[i]] = i;
        }
        return vector<int>();
    }
};
