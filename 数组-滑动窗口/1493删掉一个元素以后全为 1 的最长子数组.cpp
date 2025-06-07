//
// Created by Sire1 on 25-6-7.
//
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_length = 0;
        int left = 0;
        unordered_map<int, int> cnt;
        for (int right=0; right<nums.size();right++){
            cnt[nums[right]]++;
            while (cnt.size()>2 || (nums[right] !=1 && cnt[nums[right]]>1)){
                cnt[nums[left]]--;
                if (cnt[nums[left]] == 0)
                    cnt.erase(nums[left]);
                left++;
            }
            int len = right - left + 1;
            max_length = max(max_length, len);
        }
        return max_length - 1;
    }
};