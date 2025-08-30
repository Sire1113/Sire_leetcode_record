class Solution {
public:
    class UFS {
    private:
        vector<int> _data;
    public:
        UFS(int n){
            _data.reserve(n);
            for (int i=0; i<n; i++)
                _data[i] = i;
        }
        int find(int input){
            if (input == _data[input])
                return input;
            _data[input] = find(_data[input]);
            return _data[input];
        }
        void join(int a, int b){
            auto father_a = find(a);
            auto father_b = find(b);
            if (father_a == father_b)
                return;
            _data[father_a] = father_b;
        }
        bool is_same(int a, int b){
            return find(a) == find(b);
        }
    };
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UFS u1 = UFS(n);
        for (auto& elem: edges){
            u1.join(elem[0], elem[1]);
        }
        return u1.is_same(source, destination);
    }
};