class Solution {
public:
    vector<int> path;
    unordered_set<int> used;
    vector<vector<int>> result;
    void permuteHelper(vector<int>& nums){
        if (path.size()==nums.size()){
            result.push_back(path);
            return;
        }
        for (int i=0; i<nums.size(); i++){
            if (used.contains(nums[i]))
                continue;
            path.push_back(nums[i]);
            used.insert(nums[i]);
            permuteHelper(nums);
            path.pop_back();
            used.erase(nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permuteHelper(nums);
        return result;
    }
};