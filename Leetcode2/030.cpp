class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return {};
        int n = s.length(), wsize = words.size(), wlen = words.begin()->length();
        unordered_map<string, int> m;
        vector<int> ret;
        for(auto w : words) m[w]++;
        for(int i=0;i+wlen*wsize <= n;i++){
            unordered_map<string, int> t(m.begin(), m.end());
            for(int j=0;j<wsize;j++){
                auto sub = s.substr(i+j*wlen,wlen);
                auto cnt = t.count(sub);
                if(cnt == 0){
                    break;
                }else{
                    if(t[sub] == 1) t.erase(sub);
                    else t[sub]--;
                }
            }
            if(t.empty()) ret.push_back(i);
        }
        return ret;
    }
};
