//
// Created by Sire1 on 25-6-4.
//
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum=0;
        int current_width=0, res = 200000;
        for (int right=0; right<nums.size();right++){
            sum+=nums[right];
            while (sum>=target){
                current_width = right - left + 1;
                res = min(res, current_width);
                sum-=nums[left];
                left++;
            }
        }
        cout  << right;
        if (res == 200000) return 0;
        else return res;
    }
};