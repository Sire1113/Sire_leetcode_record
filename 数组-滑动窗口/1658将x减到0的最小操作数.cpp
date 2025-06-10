//
// Created by Sire1 on 25-6-9.
//
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), left = 0;
        int max_length = -1;
        long long sum = 0;
        int current_sum = 0;
        for (auto & elem: nums)
            sum+=elem;
        if (sum < x)
            return -1;
        for (int right = 0; right < n; right++){
            current_sum+=nums[right];
            while (sum - current_sum < x){
                current_sum-=nums[left];
                left++;
            }
            if (sum - current_sum == x){
                int len = right - left + 1;
                max_length = max(max_length, len);
            }
        }
        return max_length<0? -1: n - max_length;
    }
};