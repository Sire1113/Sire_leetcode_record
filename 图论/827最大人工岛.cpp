class Solution {
public:
    array<array<int, 2>,4> dir{1,0,0,1,-1,0,0,-1};
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y, int mark, int& area){
        area++;
        grid[x][y] = mark;
        visited[x][y] = 1;
        for (int i=0; i<4; i++){
            int next_x = x+dir[i][0];
            int next_y = y+dir[i][1];
            if (next_x<0||next_y<0||next_x>=grid.size()||next_y>=grid[0].size())
                continue;
            if (grid[next_x][next_y]==1 && visited[next_x][next_y] != 1)
                dfs(grid, visited, next_x,next_y,mark, area);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int mark{2};
        unordered_map<int, int> cnt;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),0));
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j] == 1 && visited[i][j] != 1){
                    int area = 0;
                    dfs(grid,visited,i,j,mark,area);
                    cnt[mark] = area;
                    mark++;
                }
            }
        }
        int max_area{};
        for(auto [k,v]:cnt)
            max_area = max(max_area, v);
        unordered_set<int> collections;
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                collections.clear();
                if (grid[i][j]!=0)
                    continue;
                int cur_area = 1;
                for (int k=0; k<4; k++){
                    int next_i = i + dir[k][0];
                    int next_j = j + dir[k][1];
                    if (next_i<0||next_j<0||next_i>=grid.size()||next_j>=grid[0].size())
                        continue;
                    if (grid[next_i][next_j] != 0 && !collections.contains(grid[next_i][next_j])){
                        cur_area += cnt[grid[next_i][next_j]];
                        collections.insert(grid[next_i][next_j]);
                    }
                }
                max_area = max(max_area, cur_area);
            }
        }
        return max_area;
    }
};