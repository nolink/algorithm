class Solution {
public:
    bool valid(vector<int>& board, int i, int n){
        for(int j=0;j<i;j++){
            if(board[j] == board[i] || abs(board[i] - board[j]) == i - j){
                return false;
            }
        }
        return true;
    }
    void backtrack(vector<int>& board, int i, int n, int& count){
        if(i == n){
            count++;
            return;
        }
        board.push_back(-1);
        for(int j=0;j<n;j++){
            board[i] = j;
            if(valid(board, i, n)) backtrack(board, i + 1, n, count);
        }
    }
    int totalNQueens(int n) {
        vector<int> board;
        int count = 0;
        backtrack(board, 0, n, count);
        return count;
    }
};
