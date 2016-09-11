class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.empty()) return nums;
        int count1 = 0, count2 = 0, cand1 = 0, cand2 = 1;
        for(auto num : nums){
            if(num == cand1){
                count1++;
            }else if(num == cand2){
                count2++;
            }else if(count1 == 0){
                count1 = 1;
                cand1 = num;
            }else if(count2 == 0){
                count2 = 1;
                cand2 = num;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(auto num : nums){
            if(num == cand1) count1++;
            else if(num == cand2) count2++;
        }
        vector<int> ret;
        if(count1 > nums.size() / 3) ret.push_back(cand1);
        if(count2 > nums.size() / 3) ret.push_back(cand2);
        return ret;
    }
};
