class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> ret;
        for(auto &s : strs){
            const string origin = s;
            sort(s.begin(), s.end());
            m[s].push_back(origin);
        }
        for(auto p : m){
            ret.push_back(p.second);
        }
        return ret;
    }
};
