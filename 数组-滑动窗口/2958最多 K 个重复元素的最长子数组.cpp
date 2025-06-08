//
// Created by Sire1 on 25-6-8.
//
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0, current_len = 0, max_length = 0;
        unordered_map<int, int> cnt;
        for (int right = 0; right < nums.size();right++){
            cnt[nums[right]]++;
            while (cnt[nums[right]] > k){
                cnt[nums[left]]--;
                if (cnt[nums[left]] == 0)
                    cnt.erase(nums[left]);
                left++;            }
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};