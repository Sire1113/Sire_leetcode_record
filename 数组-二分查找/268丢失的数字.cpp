//
// Created by Sire1 on 25-6-1.
//
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid, left = 0, right = nums.size() - 1;
        while (left <= right){
            mid = left + (right - left) / 2;
            if (nums[mid] == mid){
                left = mid + 1;
            }
            else{ // [0,2,3,4]
                right = mid - 1;
            }
        }
        return left;

    }
};