class NumArray {
private:
    vector<int> partial;
public:
    NumArray(vector<int> &nums) {
        if(nums.empty()) return;
        partial = vector<int>(nums.size(), nums[0]);
        for(int i=1;i<nums.size();i++){
            partial[i] = nums[i] + partial[i-1];
        }
    }

    int sumRange(int i, int j) {
        if(i == 0) return partial[j];
        return partial[j] - partial[i-1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
