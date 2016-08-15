class Solution {
public:
    vector<vector<int>> backtrack(vector<int>& candidates, int idx, int target){
        vector<vector<int>> ret;
        for(int i=idx;i<candidates.size();i++){
            int c = candidates[i];
            if(c > target){
                break;
            }else if(c == target){
                ret.push_back({target});
                break;
            }else{
                vector<vector<int>> t = backtrack(candidates, i, target - c);
                for(auto v : t){
                    v.push_back(c);
                    ret.push_back(v);
                }
            }
        }
        return ret;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return backtrack(candidates, 0, target);
    }
};
