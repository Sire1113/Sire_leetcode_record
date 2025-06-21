class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt{};
        vector<int> res{};
        for (auto& elem: nums1)
            cnt[elem]++;
        for (auto& elem: nums2){
            if (cnt.contains(elem)){
                cnt[elem]--;
                if (cnt[elem]==0)
                    cnt.erase(elem);
                res.push_back(elem);
            }
        }
        return res;
    }
};