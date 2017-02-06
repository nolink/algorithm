class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        ab c/c ab/ab
        00 1/0 01/00
        01 1/0 10/01
        10 1/0 00/10
        */
        int a = 0, b = 0;
        for(auto c : nums){
            int ta = (~a&b&c) | (a&~b&~c);
            b = (~a&~b&c) | (~a&b&~c);
            a =ta;
        }
        return a | b;
    }
};
