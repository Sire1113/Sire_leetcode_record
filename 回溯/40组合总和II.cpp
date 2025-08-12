class Solution {
public:
    void combinationSum2Helper(vector<int>& candidates, int& target, int idx, vector<int>& path, set<vector<int>>& res){
        int sum = accumulate(path.begin(), path.end(), 0);
        if (sum >= target){
            if (sum == target)
                res.insert(path);
            return;
        }
        for (int i=idx; i< candidates.size(); i++){
            if (i > idx && candidates[i] == candidates[i-1])
                continue;
            path.push_back(candidates[i]);
            combinationSum2Helper(candidates, target, i+1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        set<vector<int>> res;
        combinationSum2Helper(candidates, target, 0, path, res);
        return {res.begin(), res.end()};
    }
};