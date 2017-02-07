const int dirs[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
class Solution {
public:
    int neighbors(vector<vector<int>>& board, int m, int n, int i, int j){
        int ret = 0;
        for(auto dir : dirs){
            int inext = i + dir[0], jnext = j + dir[1];
            if(inext >= 0 && inext < m && jnext >= 0 && jnext < n){
                ret += board[inext][jnext] & 1;
            }
        }
        return ret;
    }
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board.begin()->empty()) return;
        int m = board.size(), n = board.begin()->size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int ns = neighbors(board, m, n, i, j);
                int state = 0;
                if(board[i][j] && ns == 2 || ns == 3){
                    state = 1;
                }else if(!board[i][j] && ns == 3){
                    state = 1;
                }
                board[i][j] |= (state << 1);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j] >>= 1;
            }
        }
    }
};
