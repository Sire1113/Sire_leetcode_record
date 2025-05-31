//
// Created by Sire1 on 25-5-30.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right){
            mid = (right + left) / 2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] > target){
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

//int main(){
//    auto input = vector<int>{5};
//    int target = 5;
//    auto res = Solution::search(input,target);
//    cout << res;
//}