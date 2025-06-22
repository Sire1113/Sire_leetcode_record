class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> cnt;
        for (int i=0; i<nums.size(); i++){
            if (cnt.contains(target-nums[i]) ){
                res.push_back(cnt[target-nums[i]]);
                res.push_back(i);
            }
            cnt[nums[i]] = i;
        }
        return res;
    }
};