class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix.begin()->empty()) return;
        bool firstRow = false, firstCol = false;
        int m = matrix.size(), n = matrix.begin()->size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    if(i == 0) firstRow = true;
                    if(j == 0) firstCol = true;
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for(int i=1;i<m;i++){
            if(matrix[i][0] == 0){
                for(int j=1;j<n;j++) matrix[i][j] = 0;
            }
        }
        for(int j=1;j<n;j++){
            if(matrix[0][j] == 0){
                for(int i=1;i<m;i++) matrix[i][j] = 0;
            }
        }
        if(firstRow){
            for(int j=0;j<n;j++) matrix[0][j] = 0;
        }
        if(firstCol){
            for(int i=0;i<m;i++) matrix[i][0] = 0;
        }
    }
};
