//
// Created by Sire1 on 25-6-9.
//
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        array<int, 2> cnt{0,0};
        int max_length = 0;
        int left = 0;
        for (int right=0; right < nums.size(); right++){
            cnt[nums[right]]++;
            while (cnt[0]>k){
                cnt[nums[left]]--;
                left++;
            }
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};