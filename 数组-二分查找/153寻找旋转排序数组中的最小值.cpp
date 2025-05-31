//
// Created by Sire1 on 25-5-31.
//
class Solution {
public:
    int findMin(vector<int>& nums) {
        int first = nums[0];
        int mid, left = 0, right = nums.size() - 1;
        if (nums[nums.size()-1] > nums[0]){
            return nums[0];
        }
        while (left <= right){
            mid = left + (right - left) / 2;
            if (nums[mid] < first){ // mid part2
                if (mid > 0 && nums[mid-1] < nums[mid]){
                    right = mid - 1;
                }
                else {
                    return nums[mid];
                }
            }
            else { // mid part1
                left = mid + 1;
            }
        }
        return nums[mid];
    }
};