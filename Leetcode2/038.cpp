class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0) return "";
        if(n == 1) return "1";
        string ret;
        string prev = countAndSay(n - 1);
        int count = 1;
        char c = prev[0];
        for(int i=1;i<prev.length();i++){
            if(prev[i] != c){
                ret += to_string(count) + c;
                c = prev[i];
                count = 1;
            }else{
                ++count;
            }
        }
        ret += to_string(count) + c;
        return ret;
    }
};
