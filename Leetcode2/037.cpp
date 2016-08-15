typedef unordered_set<char> uset;
class Solution {
private:
    static inline bool backtrack(vector<vector<char>>& board, vector<uset>& x, vector<uset>& y, vector<uset>& z){
        //find the first .
        int i = 0, j = 0, k = 0;
        bool found = false;
        for(i = 0;i<9;i++){
            for(j = 0;j<9;j++){
                if(board[i][j] == '.'){
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        if(!found) return true;
        k = i / 3 * 3 + j / 3;
        for(char c = '1';c<='9';c++){
            if(x[i].count(c) == 0 && y[j].count(c) == 0 && z[k].count(c) == 0){
                board[i][j] = c;
                x[i].insert(c);
                y[j].insert(c);
                z[k].insert(c);
                if(backtrack(board, x, y, z)) return true;
                x[i].erase(c);
                y[j].erase(c);
                z[k].erase(c);
                board[i][j] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<uset> x(9, uset()), y(9, uset()), z(9, uset());
        for(int i = 0, j = 0, k = 0;i<9;i++){
            for(j = 0;j<9;j++){
                if(board[i][j] != '.'){
                    k = i / 3 * 3 + j / 3;
                    x[i].insert(board[i][j]);
                    y[j].insert(board[i][j]);
                    z[k].insert(board[i][j]);
                }
            }
        }
        backtrack(board, x, y, z);
    }
};
