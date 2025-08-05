class Solution {
public:
    void combinationSumHelper(vector<int>& candidates, int& target, int idx, vector<int>& path, vector<vector<int>>& res){
        int sum = accumulate(path.begin(), path.end(),0);
        if (sum >= target){
            if (sum == target)
                res.push_back(path);
            return;
        }
        for (int i=idx; i<candidates.size(); i++){
            path.push_back(candidates[i]);
            combinationSumHelper(candidates, target, i, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> res;
        combinationSumHelper(candidates, target, 0, path, res);
        return res;
    }
};