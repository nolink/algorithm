class Solution {
public:
    void backtrack(vector<string>& ret, string chosen, string s, int idx, int level){
        if(level > 4) return;
        if(idx == s.length()){
            if(level == 4) ret.push_back(chosen);
            return;
        }
        for(int i=1;i<4 && idx + i <= s.length();i++){
            if(i > 1 && s[idx] == '0') break;
            auto sub = s.substr(idx, i);
            int intsub = stoi(sub);
            if(intsub < 256){
                backtrack(ret, chosen.empty() ? sub : chosen + "." + sub, s, idx + i, level+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        backtrack(ret, "", s, 0, 0);
        return ret;
    }
};
