class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int res{1}, pre{}, cur;
        for (int i = 0; i < nums.size() - 1; i++) {
            cur = nums[i + 1] - nums[i];
            if ((pre >= 0 && cur < 0) || (pre <= 0 && cur > 0)) {
                res++;
                pre = cur;
            }
        }
        return res;
    }
};