class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix.begin()->empty()) return false;
        int m = matrix.size(), n = matrix.begin()->size();
        for(int i=0, j=n-1;i<m && j>=0;){
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] < target){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};
