class Solution {
public:
    void combinationSum3Helper(int& k, int& n, vector<int>& path, int idx, vector<vector<int>>& res){
        int sum = accumulate(path.begin(), path.end(),0);
        if (sum > n)
            return;
        else if (n - sum > 9 *(k-path.size()))
            return;
        if (path.size()==k){
            if (sum == n)
                res.push_back(path);
            return;
        }
        for (int i=idx; i<10; i++){
            path.push_back(i);
            combinationSum3Helper(k,n,path, i+1, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        combinationSum3Helper(k,n,path, 1, res);
        return res;
    }
};