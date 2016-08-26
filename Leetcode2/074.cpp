class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix.begin()->empty()) return false;
        int m = matrix.size(), n = matrix.begin()->size();
        int rowLow = 0, rowHigh = m - 1;
        while(rowLow < rowHigh){
            int mid = rowLow + (rowHigh - rowLow) / 2;
            if(matrix[mid][n-1] == target){
                return true;
            }else if(matrix[mid][n-1] < target){
                rowLow = mid + 1;
            }else{
                rowHigh = mid;
            }
        }
        auto it = lower_bound(matrix[rowLow].begin(), matrix[rowLow].end(), target);
        return it != matrix[rowLow].end() && *it == target;
    }
};
