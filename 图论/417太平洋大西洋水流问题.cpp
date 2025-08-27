class Solution {
public:
    bool bfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int x, int y){
        queue<pair<int,int>> q;
        q.push({x,y});
        visited[x][y] = 1;
        array<array<int,2>, 4> dir = {0,1,1,0,-1,0,0,-1};
        while (!q.empty()){
            auto [cur_x, cur_y] = q.front();q.pop();
            for (int i=0; i<4; i++){
                int next_x = cur_x + dir[i][0];
                int next_y = cur_y + dir[i][1];
                if (next_x < 0 || next_x >= heights.size() || next_y < 0 || next_y >= heights[0].size())
                    continue;
                if (heights[cur_x][cur_y] <= heights[next_x][next_y] && visited[next_x][next_y] != 1){
                    visited[next_x][next_y] = 1;
                    q.push({next_x,next_y});
                }
            }
        }
        return false;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> Pacific(heights.size(), vector<int>(heights[0].size(),0));
        vector<vector<int>> Atlantic(heights.size(), vector<int>(heights[0].size(),0));
        vector<vector<int>> res;
        for (int i=0; i<heights.size(); i++){
            bfs(heights, Pacific, i,0);
            bfs(heights, Atlantic, i,heights[0].size()-1);
        }
        for (int j=0; j<heights[0].size(); j++){
            bfs(heights, Pacific, 0, j);
            bfs(heights, Atlantic, heights.size()-1, j);
        }
        for (int i=0; i<heights.size(); i++){
            for (int j=0; j<heights[0].size(); j++){
                if (Pacific[i][j] == 1 && Atlantic[i][j] == 1)
                    res.push_back({i,j});
            }
        }
        return res;
    }
};