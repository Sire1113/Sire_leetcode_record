class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        array<array<int,2>,4> dir = {0,1,0,-1,1,0,-1,0};
        int cnt{};
        for (int x=0; x<grid.size(); x++){
            for (int y=0; y<grid[0].size(); y++){
                if (grid[x][y] == 0)
                    continue;
                for (int i=0; i<4; i++){
                    int next_x = x+dir[i][0];
                    int next_y = y+dir[i][1];
                    if (next_x<0||next_y<0||next_x>=grid.size()||next_y>=grid[0].size()){
                        cnt++;
                        continue;
                    }
                    if (grid[next_x][next_y] != 1)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};