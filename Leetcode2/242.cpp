class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen = s.length(), tlen = t.length();
        if(slen != tlen) return false;
        vector<int> aux(26, 0);
        for(int i=0;i<slen;i++){
            aux[s[i]-'a']++;
            aux[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(aux[i] != 0) return false;
        }
        return true;
    }
};
