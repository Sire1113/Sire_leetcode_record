class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void findSubsequencesHelper(vector<int>& nums, int idx){
        if (path.size()>1)
            res.push_back(path);
        unordered_set<int> used;
        for (int i=idx; i<nums.size(); i++){
            if (used.contains(nums[i]) || (!path.empty() && path[path.size()-1] > nums[i]))
                continue;
            used.insert(nums[i]);
            path.push_back(nums[i]);
            findSubsequencesHelper(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        findSubsequencesHelper(nums,0);
        return res;
    }
};