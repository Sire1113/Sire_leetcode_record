//
// Created by Sire1 on 25-6-6.
//
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> res(nums.size(),-1);
        long long current = 0;
        for (int i =0; i < nums.size(); i++){
            current+=(nums[i]);
            if (i<k*2){
                continue;
            }
            res[i-k]=(current)/(k*2+1);
            current-=(nums[i-k*2]);
        }
        int num = nums.size()-res.size();
        return res;
    }
};