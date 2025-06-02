//
// Created by Sire1 on 25-6-2.
//
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fast = 1, slow = 1;
        for (;fast < nums.size();fast++){
            if (nums[fast]!=nums[fast-1]){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};