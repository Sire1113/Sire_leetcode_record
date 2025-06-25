class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
            return {};
        vector<vector<int>> res;
        int left, right;
        sort(nums.begin(), nums.end());
        for (int k=0; k<nums.size()-3; k++){
            if (nums[k]>target && target>=0)
                break;
            if (k>0 && nums[k]==nums[k-1])
                continue;
            for (int i=k+1; i<nums.size()-2; i++){
                if (i>k+1 && nums[i]==nums[i-1])
                    continue;
                left = i +1 ;
                right = nums.size()-1;
                while (left < right){
                    long long sum = static_cast<long long>(nums[i])+static_cast<long long>(nums[k])+static_cast<long long>(nums[left])+static_cast<long long>(nums[right]);
                    if (sum > target)
                        right--;
                    else if (sum < target)
                        left++;
                    else {
                        res.push_back({nums[k], nums[i], nums[left], nums[right]});
                        while (left < right && nums[left]==nums[left+1])
                            left++;
                        while (left < right && nums[right]==nums[right-1])
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};