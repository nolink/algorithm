class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret(2, 0);
        int n = numbers.size();
        for(int i=n-1;i>0;i--){
            ret[1] = i + 1;
            int expect = target - numbers[i];
            auto it = upper_bound(numbers.begin(), numbers.begin() + i, expect);
            if(it != numbers.begin() && *(it - 1) == expect){
                ret[0] = it - numbers.begin();
                break;
            }
        }
        return ret;
    }
};
