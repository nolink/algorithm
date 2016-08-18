class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret;
        if(n == 0) return ret;
        ret = vector<vector<int>>(n, vector<int>(n, 0));
        for(int i = 0;i<n;i++) ret[0][i] = i + 1;
        int dr[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
        for(int dridx = 0, num = n + 1, i = 0, j = n-1, m = n, expect = n*n;num <= expect;dridx = (dridx + 1) % 4){
            for(int k = 1;k<m;k++){
                i += dr[dridx][0];
                j += dr[dridx][1];
                ret[i][j] = num;
                num++;
            }
            m--;
            swap(m, n);
        }
        return ret;
    }
};
