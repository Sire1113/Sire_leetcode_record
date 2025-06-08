//
// Created by Sire1 on 25-6-8.
//
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0, max_length = 0, current_score = 0;
        unordered_map<int, int> cnt;
        for (int right=0;right<nums.size(); right++){
            cnt[nums[right]]++;
            current_score+=nums[right];
            while (cnt.size()!=right - left + 1){
                current_score -= nums[left];
                cnt[nums[left]]--;
                if (cnt[nums[left]] == 0)
                    cnt.erase(nums[left]);
                left++;
            }
            max_length = max(max_length, current_score);
        }
        return max_length;
    }
};