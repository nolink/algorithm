class Solution {
public:
    bool isValid(string s) {
        stack<int> aux;
        for(auto c : s){
            if(c == '(' || c == '[' || c == '{'){
                aux.push(c);
            }else if(!aux.empty()){
                auto t = aux.top();
                if((t == '(' && c == ')') || (t == '[' && c == ']') || (t == '{' && c == '}')) aux.pop();
                else return false;
            }else{
                return false;
            }
        }
        return aux.empty();
    }
};
