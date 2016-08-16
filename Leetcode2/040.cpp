class Solution {
public:
    vector<vector<int>> backtrack(vector<int>& candidates, int idx, int target){
        vector<vector<int>> ret;
        if(idx >= candidates.size()) return ret;
        for(int i=idx;i<candidates.size();){
            int c = candidates[i];
            if(c > target){
                break;
            }else if(c == target){
                ret.push_back({target});
                break;
            }else{
                auto t = backtrack(candidates, i + 1, target - c);
                for(auto v : t){
                    v.push_back(c);
                    ret.push_back(v);
                }
                //skip dup
                while(i < candidates.size() && candidates[i] == c) i++;
            }
        }
        return ret;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return backtrack(candidates, 0, target);
    }
};
