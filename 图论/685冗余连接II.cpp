class Solution {
public:
    class UFS {
    private:
        vector<int> father;
    public:
        UFS(int n) {
            n = n + 2;
            father.reserve(n);
            for (int i = 0; i < n; i++)
                father[i] = i;
        }
        int find(int n) {
            if (father[n] == n)
                return n;
            father[n] = find(father[n]);
            return father[n];
        }
        void join(int a, int b) {
            auto father_a = find(a);
            auto father_b = find(b);
            if (father_a == father_b)
                return;
            father[father_a] = father_b;
        }
        bool is_same(int a, int b) { return find(a) == find(b); }
    };
    bool is_right_tree(vector<vector<int>>& edges, vector<int> edge){
        UFS u1(edges.size()+1);
        for (auto& e:edges){
            if (e == edge) continue;
            u1.join(e[0],e[1]);
        }
        return u1.is_same(edge[0], edge[1]);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> indegree(edges.size()+1,0);
        vector<vector<int>> need_edge;
        for (auto& edge:edges)
            indegree[edge[1]]++;
        for (auto& edge:edges){
            if (indegree[edge[1]] == 2)
                need_edge.push_back(edge);
        }
        if (need_edge.size()>0){
            if (is_right_tree(edges, need_edge[1]))
                return need_edge[1];
            return need_edge[0];
        }
        UFS u1(edges.size()+1);
        for (auto& edge:edges){
            if (u1.is_same(edge[0], edge[1]))
                return edge;
            u1.join(edge[0], edge[1]);
        }
        return {};
    }
};