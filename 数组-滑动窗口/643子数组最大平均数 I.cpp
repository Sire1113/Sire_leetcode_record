//
// Created by Sire1 on 25-6-6.
//
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_avg = -10000;
        double current = 0;
        for (int i=0;i<nums.size();i++){
            current+=static_cast<double>(nums[i]) /k;
            if (i<k-1){
                continue;
            }
            max_avg = max(max_avg, current);
            current -= static_cast<double>(nums[i-k+1]) /k;
        }
        return max_avg;
    }
};