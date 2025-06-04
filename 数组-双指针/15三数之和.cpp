//
// Created by Sire1 on 25-6-4.
//
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3){
            return {};
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for (int i=0; i< nums.size()-2; i++){
            if (nums[i] > 0){
                return res;
            }
            if (i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i+1, right = nums.size() - 1;
            while (left < right){
                if (nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }
                else {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    res.push_back(temp);
                    while (left<right && nums[left] == nums[left+1]) left++; // 去重
                    while (left<right && nums[right] == nums[right-1]) right--; // 去重
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};