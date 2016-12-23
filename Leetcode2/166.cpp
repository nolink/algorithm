class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string ret = ((numerator > 0) ^ (denominator > 0)) ? "-" : "";
        long num = labs(numerator);
        long den = labs(denominator);
        
        ret += to_string(num / den);
        num %= den;
        if(num == 0) return ret;
        
        ret += ".";
        unordered_map<int, int> m;
        m[num] = ret.length();
        
        while(num > 0){
            num *= 10;
            ret += to_string(num / den);
            num %= den;
            if(m.count(num) > 0){
                ret = ret.substr(0, m[num]) + "(" + ret.substr(m[num]) + ")";
                break;
            }else{
                m[num] = ret.length();
            }
        }
        
        return ret;
    }
};
