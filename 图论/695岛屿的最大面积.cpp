
//bfs
class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y) {
        int area{1};
        queue<pair<int, int>> q;
        q.push({x, y});
        array<array<int, 2>, 4> dir{0, 1, 1, 0, -1, 0, 0, -1};
        while (!q.empty()) {
            auto [cur_x, cur_y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int next_x = cur_x + dir[i][0];
                int next_y = cur_y + dir[i][1];
                if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size())
                    continue;
                if (grid[next_x][next_y] == 1 && visited[next_x][next_y] != 1) {
                    visited[next_x][next_y] = 1;
                    q.push({next_x, next_y});
                    area++;
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area{};
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && visited[i][j] != 1) {
                    visited[i][j] = 1;
                    max_area = max(max_area, bfs(grid, visited, i, j));
                }
            }
        }
        return max_area;
    }
};

// dfs
class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x,
             int y, int& area) {
        array<array<int, 2>, 4> dir{0, 1, 1, 0, -1, 0, 0, -1};
        visited[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if (next_x < 0 || next_x >= grid.size() || next_y < 0 ||
                next_y >= grid[0].size())
                continue;
            if (grid[next_x][next_y] == 1 && visited[next_x][next_y] != 1) {
                visited[next_x][next_y] = 1;
                area++;
                dfs(grid, visited, next_x, next_y, area);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area{};
        vector<vector<int>> visited(grid.size(),
                                    vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && visited[i][j] != 1) {
                    int area{1};
                    dfs(grid, visited, i, j, area);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};