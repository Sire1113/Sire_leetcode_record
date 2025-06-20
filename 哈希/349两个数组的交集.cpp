
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> cnt;
        for (auto& elem: nums1)
            cnt.insert(elem);
        for (auto& elem: nums2){
            if (cnt.contains(elem)){
                cnt.erase(elem);
                res.push_back(elem);
            }

        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)