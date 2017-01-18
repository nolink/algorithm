class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix.begin()->empty()) return 0;
        int ret = 0;
        int m = matrix.size(), n = matrix.begin()->size();
        vector<int> heights(n+1, 0);
        for(int i=0;i<m;i++){
            stack<int> s;
            for(int j=0;j<=n;j++){
                if(j < n){
                    if(matrix[i][j] == '0'){
                        heights[j] = 0;
                    }else{
                        heights[j]++;
                    }
                }
                while(!s.empty() && heights[s.top()] >= heights[j]){
                    int k = s.top();
                    s.pop();
                    int width = -1;
                    if(s.empty()){
                        width = j;
                    }else{
                        width = j - s.top() - 1;
                    }
                    ret = max(ret, width * heights[k]);
                }
                s.push(j);
            }
        }
        return ret;
    }
};
