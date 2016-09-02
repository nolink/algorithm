class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
        stack<int> s;
        for(auto token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                if(token == "+"){
                    s.push(op1 + op2);
                }else if(token == "-"){
                    s.push(op1 - op2);
                }else if(token == "*"){
                    s.push(op1 * op2);
                }else{
                    s.push(op1 / op2);
                }
            }else{
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
