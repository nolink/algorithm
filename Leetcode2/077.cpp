class Solution {
public:
    void backtrack(vector<vector<int>>& ret, vector<int>& chosen, int begin, int n, int k){
        if(k == 0){
            ret.push_back(chosen);
            return;
        }
        for(int i=begin;i+k<=n+1;i++){
            chosen.push_back(i);
            backtrack(ret, chosen, i + 1, n, k - 1);
            chosen.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> chosen;
        backtrack(ret, chosen, 1, n, k);
        return ret;
    }
};
