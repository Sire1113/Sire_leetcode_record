class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void subsetsWithDupHelper(vector<int>& nums, int idx) {
        res.push_back(path);
        for (int i=idx; i<nums.size(); i++){
            if (i>idx && nums[i] == nums[i-1])
                continue;
            path.push_back(nums[i]);
            subsetsWithDupHelper(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        subsetsWithDupHelper(nums, 0);
        return res;
    }
};