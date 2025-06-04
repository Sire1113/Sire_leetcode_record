//
// Created by Sire1 on 25-6-4.
//
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while (left < right){
            if (numbers[left] + numbers[right] > target){
                right--;
            }
            else if (numbers[left] + numbers[right] < target) {
                left++;
            }
            else {
                break;
            }
        }
        return {left+1, right+1};
    }
};