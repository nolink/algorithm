class Solution {
public:
    bool backtrack(string s, int sidx, string p, int pidx, vector<int>& dp){
        int& ret = dp[sidx];
        if(ret != -1) return ret;
        while(pidx < p.length() && sidx < s.length() && (s[sidx] == p[pidx] || p[pidx] == '?')){
            pidx++;
            sidx++;
        }
        if(pidx == p.length()) return (ret = (sidx == s.length()));
        if(p[pidx] == '*'){
            for(int skip=0;sidx+skip<=s.length();skip++){
                if(backtrack(s, sidx + skip, p, pidx + 1, dp)) return (ret = true);
            }
        }
        return (ret = false);
    }
    bool isMatch(string s, string p) {
        vector<int> dp(s.length() + 1, -1);
        return backtrack(s, 0, p, 0, dp);
    }
};
