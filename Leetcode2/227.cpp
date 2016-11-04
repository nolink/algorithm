class Solution {
public:
    int calculate(string s) {
        stack<int> oprand;
        stack<char> op;
        int num = 0;
        for(auto c : s){
            if(isspace(c)) continue;
            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }else{
                oprand.push(num);
                while(!op.empty()){
                    char prev = op.top();
                    if(c == '+' || c == '-' || prev == '*' || prev == '/'){
                        int op2 = oprand.top();
                        oprand.pop();
                        int op1 = oprand.top();
                        oprand.pop();
                        if(prev == '+'){
                            oprand.push(op1 + op2);
                        }else if(prev == '-'){
                            oprand.push(op1 - op2);
                        }else if(prev == '*'){
                            oprand.push(op1 * op2);
                        }else{
                            oprand.push(op1 / op2);
                        }
                        op.pop();
                    }else{
                        break;
                    }
                }
                op.push(c);
                num = 0;
            }
        }
        //one + or -
        //one + or -, and one * or /
        while(!op.empty()){
            char c = op.top();
            op.pop();
            int op1 = oprand.top();
            oprand.pop();
            if(c == '*'){
                num = op1 * num;
            }else if(c == '/'){
                num = op1 / num;
            }else if(c == '+'){
                num = op1 + num;
            }else{
                num = op1 - num;
            }
        }
        return num;
    }
};
