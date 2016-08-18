class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty() || matrix.begin()->empty()) return ret;
        ret = matrix[0];
        int dridx = 0, m = matrix.size(), n = matrix.begin()->size();
        int dr[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0,1}};
        for(int count = (m-1)*n, i = 0, j = n-1;count > 0;dridx = (dridx + 1) % 4){
            for(int k=1;k<m;k++){
                i += dr[dridx][0];
                j += dr[dridx][1];
                ret.push_back(matrix[i][j]);
                count--;
            }
            m--;
            swap(m, n);
        }
        return ret;
    }
};
