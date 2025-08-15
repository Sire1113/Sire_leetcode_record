class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int next{}, cur{}, res{};
        for (int i = 0; i < nums.size(); i++) {
            next = max(next, i + nums[i]);
            if (i == cur) {
                res++;
                cur = next;
            }
            if (cur >= nums.size() - 1)
                break;
        }
        return res;
    }
};