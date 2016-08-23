class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for(int i=0;i<numRows;i++){
            vector<int> inner(i+1, 1);
            for(int j=1;j<i;j++){
                inner[j] = ret[i-1][j-1] + ret[i-1][j];
            }
            ret.push_back(inner);
        }
        return ret;
    }
};
