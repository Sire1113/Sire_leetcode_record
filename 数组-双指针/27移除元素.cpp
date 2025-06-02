//
// Created by Sire1 on 25-6-2.
//
#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast = 0, slow = 0;
        for (;fast<nums.size();fast++){
            if (nums[fast] != val){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

