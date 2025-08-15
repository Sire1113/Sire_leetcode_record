class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover{};
        for (int i=0; i<=cover; i++){
            cover = max(cover, i+nums[i]);
            if (cover >= nums.size()-1)
                return true;
        }
        return false;
    }
};