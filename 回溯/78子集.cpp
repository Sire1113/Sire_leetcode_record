class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void subsetsHelper(vector<int>& nums, int idx){
        res.push_back(path);
        for (int i=idx; i<nums.size(); i++){
            path.push_back(nums[i]);
            subsetsHelper(nums ,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        subsetsHelper(nums, 0);
        return res;
    }
};