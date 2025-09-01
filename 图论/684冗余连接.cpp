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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        auto u1 = UFS(edges.size());
        for (auto& elem : edges) {
            if (u1.is_same(elem[0], elem[1]))
                return elem;
            u1.join(elem[0], elem[1]);
        }
        return {};
    }
};