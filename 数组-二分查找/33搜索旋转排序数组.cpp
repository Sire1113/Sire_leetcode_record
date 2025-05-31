//
// Created by Sire1 on 25-5-31.
//
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = nums[0],end = nums[nums.size() - 1];
        int mid, left = 0, right = nums.size() - 1;
        while (left <= right){
            mid = left + (right - left) / 2;
            if (nums[mid] > target){
                if (nums[mid] < first){ // mid 在第二部分
                    right = mid - 1;
                }
                else{ // mid 在第一部分
                    if (target < first) { // target 在第二部分
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1; // target 在第一部分
                    }
                }
            }
            else if (nums[mid] < target){
                if (nums[mid] < first){ // mid 在第二部分
                    if (target < first) { // target 在第二部分
                        left = mid + 1;
                    }
                    else {              // target 在第一部分
                        right = mid - 1;
                    }
                }
                else{ // mid 在第一部分
                    left = mid + 1;
                }
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};