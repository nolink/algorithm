class Solution {
public:

    static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
    }
    
    // trim from end
    static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(),
                std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
    }
    
    // trim from both ends
    static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
    }

    bool isNumber(string s) {
        s = trim(s);
    
        bool pointSeen = false;
        bool eSeen = false;
        bool numberSeen = false;
        bool numberAfterE = true;
        for(int i=0; i<s.size(); i++) {
            if('0' <= s[i] && s[i] <= '9') {
                numberSeen = true;
                numberAfterE = true;
            } else if(s[i] == '.') {
                if(eSeen || pointSeen) {
                    return false;
                }
                pointSeen = true;
            } else if(s[i] == 'e') {
                if(eSeen || !numberSeen) {
                    return false;
                }
                numberAfterE = false;
                eSeen = true;
            } else if(s[i] == '-' || s[i] == '+') {
                if(i != 0 && s[i-1] != 'e') {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        return numberSeen && numberAfterE;
    }
};
