class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1;i>=0;i--){
            digits[i] += carry;
            carry = digits[i] > 9 ? 1: 0;
            digits[i] %= 10;
        }
        if(carry == 1){
            vector<int> ret(1, 1);
            ret.insert(ret.end(), digits.begin(), digits.end());
            return ret;
        }else{
            return digits;
        }
    }
};
