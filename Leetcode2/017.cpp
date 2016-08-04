const string mapping[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:
    void backtrack(vector<string>& ret, string chosen, string digits, int idx){
        if(idx == digits.length()){
            ret.push_back(chosen);
            return;
        }
        int d = digits[idx] - '0';
        if(d == 0 || d == 1){
            backtrack(ret, chosen, digits, idx+1);
        }
        else{
            for(int i=0;i<mapping[d-2].length();i++){
                backtrack(ret, chosen + mapping[d-2][i], digits, idx+1);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(!digits.empty()) backtrack(ret, "", digits, 0);
        return ret;
    }
};
