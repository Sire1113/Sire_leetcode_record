class Solution {
public:
    vector<vector<int>> res;
    vector<int> path{0};
    void dfs(vector<vector<int>>& graph, int node){
        if (node==graph.size()-1)
            res.push_back(path);
        if (graph[node].size()==0)
            return;
        for (auto& next: graph[node]){
            path.push_back(next);
            dfs(graph, next);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return res;
    }
};