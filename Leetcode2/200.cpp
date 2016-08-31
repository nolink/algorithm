
const int drs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class Solution {
public:
    void dfs(unordered_map<int, unordered_set<int>>& um, vector<vector<bool>>& visited, int i, int j){
        visited[i][j] = true;
        for(auto dr : drs){
            int inext = i + dr[0], jnext = j + dr[1];
            if(um.count(inext) && um[inext].count(jnext) && !visited[inext][jnext]){
                dfs(um, visited, inext, jnext);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid.begin()->empty()) return 0;
        int m = grid.size(), n = grid.begin()->size(), count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        unordered_map<int, unordered_set<int>> um;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1') um[i].insert(j);
            }
        }
        for(auto i : um){
            for(auto j : i.second){
                if(!visited[i.first][j]){
                    dfs(um, visited, i.first, j);
                    count++;
                }
            }
        }
        return count;
    }
};
