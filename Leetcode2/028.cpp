class Solution {
public:
    void prepare(vector<int>& pi, string needle){
        int begin = 1, matched = 0, nlen = needle.length();
        while(begin + matched < nlen){
            if(matched < nlen && needle[matched] == needle[begin+matched]){
                matched++;
                pi[begin+matched-1] = matched;
            }else{
                if(matched == 0){
                    begin++;
                }else{
                    begin += matched - pi[matched-1];
                    matched = pi[matched-1];
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.empty() || haystack == needle) return 0;
        int hlen = haystack.length(), nlen = needle.length();
        vector<int> pi(nlen, 0);
        prepare(pi, needle);
        int begin = 0, matched = 0;
        while(begin + matched <= hlen){
            if(matched < nlen && haystack[matched+begin] == needle[matched]){
                matched++;
                if(matched == nlen){
                    return begin;
                }
            }else{
                if(matched == 0){
                    begin++;
                }else{
                    begin += matched - pi[matched-1];
                    matched = pi[matched-1];
                }
            }
        }
        return -1;
    }
};
