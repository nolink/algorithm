class Solution {
public:
    void backtrack(vector<vector<int>>& ret, vector<int> chosen, queue<int>& nums){
        if(nums.empty()){
            ret.push_back(chosen);
            return;
        }
        int n = nums.size(), len = chosen.size();
        chosen.push_back(-1);
        for(int i=0;i<n;i++){
            int aux = nums.front();
            chosen[len] = aux;
            nums.pop();
            backtrack(ret, chosen, nums);
            nums.push(aux);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        queue<int> q;
        for(auto n : nums) q.push(n);
        backtrack(ret, vector<int>(), q);
        return ret;
    }
};
