//
// Created by Sire1 on 25-6-6.
//
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int ,int> cnt;
        long long res = 0;
        long long current = 0;
        for (int i=0;i<nums.size();i++){
            current+=nums[i];
            cnt[nums[i]]++;
            if (i<k-1)
                continue;
            if (cnt.size() == k)
                res = max(res, current);
            current-=nums[i-k+1];
            cnt[nums[i-k+1]]--;
            if (cnt[nums[i-k+1]]==0)
                cnt.erase(nums[i-k+1]);
        }
        return res;
    }
};