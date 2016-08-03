class Solution {
public:
    int myAtoi(string str) {
        long ret = 0;
        int i = 0, n = str.length();
        bool negative = false;
        while(i < n && isspace(str[i])) i++;
        if(i < n && (str[i] == '-' || str[i] == '+')){
            negative = str[i] == '-';
            i++;
        }
        while(i < n){
            if(!isdigit(str[i])) break;
            ret = ret * 10 + (str[i] - '0');
            if(ret - 1 > INT_MAX) break;
            i++;
        }
        return negative ? (-ret < INT_MIN ? INT_MIN : -ret) : (ret > INT_MAX ? INT_MAX : ret);
    }
};
