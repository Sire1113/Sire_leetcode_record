class Solution {
public:
    void combineHelper(int& n, int& k, vector<int>& path, int idx,  vector<vector<int>>& res){
        if (path.size()==k)
            res.push_back(path);
        for (int i = idx; i<=n; i++){
            path.push_back(i);
            combineHelper(n,k,path,i+1,res);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> res;
        combineHelper(n,k,path,1,res);
        return res;
    }
};