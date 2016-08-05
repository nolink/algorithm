class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n <= 0) return {""};
        if(n == 1) return {"()"};
        vector<string> ret;
        for(int i=0;i<(n+1)/2;i++){
            auto part1 = generateParenthesis(i);
            auto part2 = generateParenthesis(n-i-1);
            for(auto p1 : part1){
                for(auto p2 : part2){
                    ret.push_back("(" + p2 + ")" + p1);
                    if(i != n - i -1) ret.push_back("(" + p1 + ")" + p2);
                }
            }
        }
        return ret;
    }
};
