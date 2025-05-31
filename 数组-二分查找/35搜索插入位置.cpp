//
// Created by Sire1 on 25-5-30.
//
#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid,left = 0,right=nums.size() - 1;
        while (left <= right){
            mid = (left + right) / 2;
            if (nums[mid] > target){
                right = mid - 1;
            }
            else if (nums[mid] < target){
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
        return left;
    }
};