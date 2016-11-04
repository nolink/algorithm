class Solution {
public:
    int expr(string s, int& idx){
        char prevc = '\0';
        int prevnum = 0;
        int num = 0;
        while(idx < s.length()){
            char c = s[idx++];
            if(isspace(c)){
                continue;
            }else if(c == ')'){
                break;
            }else if(isdigit(c)){
                num = num * 10 + (c - '0');
            }else if(c == '('){
                num = expr(s, idx);
            }else if(c == '+' || c == '-'){
                if(prevc != '\0'){
                    prevnum = prevc == '+' ? prevnum + num : prevnum - num;
                }else{
                    prevnum = num;
                }
                prevc = c;
                num = 0;
            }
        }
        if(prevc != '\0'){
            num = prevc == '+' ? prevnum + num : prevnum - num;
        }
        return num;
    }
    int calculate(string s) {
        int idx = 0;
        return expr(s, idx);
    }
};
