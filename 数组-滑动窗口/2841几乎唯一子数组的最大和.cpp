//
// Created by Sire1 on 25-6-6.
//
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long res = 0;
        long long current = 0;
        unordered_map<int, int> cnts;
        for (int i = 0;i<nums.size();i++){
            current += nums[i];
            cnts[nums[i]]++;
            if (i<k-1)
                continue;
            if (cnts.size()>=m)
                res = max(res, current);
            current-=nums[i-k+1];
            cnts[nums[i-k+1]]--;
            if (cnts[nums[i-k+1]] == 0)
                cnts.erase(nums[i-k+1]);
        }
        return res;
    }
};