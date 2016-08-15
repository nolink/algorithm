class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> x(9, unordered_set<char>()), y(9, unordered_set<char>()), z(9, unordered_set<char>());
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                int zidx = i / 3 * 3 + j / 3;
                if(c != '.'){
                    if(x[i].count(c) || y[j].count(c) || z[zidx].count(c)) return false;
                    x[i].insert(c);
                    y[j].insert(c);
                    z[zidx].insert(c);
                }
            }
        }
        return true;
    }
};
