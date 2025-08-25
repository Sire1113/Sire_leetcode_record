class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited,int x,int y){
        array<array<int, 2>, 4> dir{0,1,1,0,-1,0,0,-1};
        for (int i=0; i<4; i++){
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if (next_x < 0 || next_x >= grid.size() ||next_y < 0 || next_y >= grid[0].size())
                continue;
            if (visited[next_x][next_y] != 1 && grid[next_x][next_y] == '1'){
                visited[next_x][next_y] = 1;
                dfs(grid, visited, next_x, next_y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),0));
        int res{};
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[i].size(); j++){
                if (auto coord = grid[i][j]; coord== '1' && visited[i][j]!=1){
                    visited[i][j] = 1;
                    res++;
                    dfs(grid, visited,i,j);
                }
            }
        }
        return res;
    }
};