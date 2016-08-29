
const int drs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    bool backtrack(vector<vector<char>>& board, int m, int n, vector<vector<bool>>& visited, int i, int j, string word, int idx){
        if(idx == word.length()) return true;
        for(auto dr : drs){
            int inext = i + dr[0], jnext = j + dr[1];
            if(inext >= 0 && inext < m && board[inext][jnext] == word[idx] && !visited[inext][jnext]){
                visited[inext][jnext] = true;
                if(backtrack(board, m, n, visited, inext, jnext, word, idx + 1)) return true;
                visited[inext][jnext] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board.begin()->empty() || word.empty()) return false;
        int m = board.size(), n = board.begin()->size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = true;
                if(board[i][j] == word[0] && backtrack(board, m, n, visited, i, j, word, 1)) return true;
                visited[i][j] = false;
            }
        }
        return false;
    }
};
