class Solution {
public:
    static inline bool backtrack(string s, string p, int sidx, int pidx){
        if(pidx == p.length()) return sidx == s.length();
        if(pidx + 1 < p.length() && p[pidx+1] == '*'){
            do{
                if(backtrack(s, p, sidx, pidx+2)) return true;
            }while(sidx < s.length() && (p[pidx] == s[sidx++] || p[pidx] == '.'));
        }else if(sidx < s.length() && (p[pidx] == s[sidx] || p[pidx] == '.')){
            return backtrack(s, p, sidx+1, pidx+1);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        return backtrack(s, p, 0, 0);
    }
};
