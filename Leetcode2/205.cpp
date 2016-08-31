class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s == t) return true;
        unordered_map<char, char> m;
        unordered_map<char, char> mreverse;
        for(int i=0;i<s.length();i++){
            if((m.count(s[i]) && m[s[i]] != t[i]) || (mreverse.count(t[i]) && mreverse[t[i]] != s[i])) return false;
            m[s[i]] = t[i];
            mreverse[t[i]] = s[i];
        }
        return true;
    }
};
