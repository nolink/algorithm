class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        int num = 0;
        bool hasOperator = false;
        for(int i=0;i<input.length();i++){
            if(!isdigit(input[i])){
                hasOperator = true;
                vector<int> sub1 = diffWaysToCompute(input.substr(0, i));
                vector<int> sub2 = diffWaysToCompute(input.substr(i+1));
                for(auto s1 : sub1){
                    for(auto s2 :sub2){
                        if(input[i] == '+'){
                            ret.push_back(s1 + s2);
                        }else if(input[i] == '-'){
                            ret.push_back(s1 - s2);
                        }else if(input[i] == '*'){
                            ret.push_back(s1 * s2);
                        }else{
                            ret.push_back(s1 / s2);
                        }
                    }
                }
            }else{
                num = num * 10 + (input[i] - '0');
            }
        }
        if(!hasOperator) ret.push_back(num);
        return ret;
    }
};
