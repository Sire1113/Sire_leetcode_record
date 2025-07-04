//
// Created by Sire1 on 25-6-3.
//
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        while (left < right){
            max_area = max(max_area, min(height[left], height[right]) * (right - left));
            if (height[left] > height[right]){
                right--;
            }
            else {
                left++;
            }
        }
        return max_area;
    }
};