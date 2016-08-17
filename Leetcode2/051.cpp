class Solution {
public:
    bool valid(vector<string>& board, int i, int j, int n){
        for(int k = 0;k<i;k++){
            if(board[k][j] == 'Q') return false;
        }
        for(int k = 1;i >= k && j >= k;k++){
            if(board[i-k][j-k] == 'Q') return false;
        }
        for(int k = 1;i >= k && j + k < n;k++){
            if(board[i-k][j+k] == 'Q') return false;
        }
        return true;
    }
    void backtrack(vector<vector<string>>& ret, vector<string>& board, int i, int n){
        if(i == n){
            ret.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            board[i][j] = 'Q';
            if(valid(board, i, j, n)) backtrack(ret, board, i + 1, n);
            board[i][j] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> board(n, string(n, '.'));
        backtrack(ret, board, 0, n);
        return ret;
    }
};
