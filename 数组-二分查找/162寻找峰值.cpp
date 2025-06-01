//
// Created by Sire1 on 25-6-1.
//
class Solution {
public:
    bool isTop(vector<int>& nums, int value){
        int n = nums.size() - 1;
        if (value == 0 ){
            if (nums[0] > nums[1]) return true;
            else return false;
        }
        else if (value == n){
            if (nums[n] > nums[n-1]) return true;
            else return false;
        }
        else {
            if (nums[value] > nums[value-1] && nums[value] > nums[value+1]){
                return true;
            }
            else {
                return false;
            }
        }
    }

    int findPeakElement(vector<int>& nums) {
        int mid, left = 0, right = nums.size() - 1;
        if (right == 0){
            return 0;
        }
        while (left <= right){
            mid = left + (right - left) / 2;
            if (mid < nums.size() - 1 && mid > 0){
                if (isTop(nums, mid)){
                    return mid;
                }
                else if (nums[mid] < nums[mid+1]){
                    left = mid + 1;
                }
                else if (nums[mid] < nums[mid-1]){
                    right = mid - 1;
                }

            }
            else if(mid == 0){
                if (isTop(nums,0)) return 0;
                else left = mid+1;
            }
            else {
                if (isTop(nums, mid)) return mid;
                else right = mid - 1;
            }
        }
        return -1;

    }
};