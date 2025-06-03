//
// Created by Sire1 on 25-6-3.
//
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (auto& elem:nums){
            elem = elem*elem;
        }
        vector<int> ret(nums.size());
        int idx=nums.size()-1, left = 0, right = idx;
        for (;idx >= 0; idx--){
            if (nums[left] > nums[right]){
                ret[idx] = nums[left];
                left++;
            }
            else {
                ret[idx] = nums[right];
                right--;
            }
        }
        return ret;
    }
};