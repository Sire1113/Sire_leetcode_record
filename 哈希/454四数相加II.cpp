class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> cnt;
        int res{};
        for (auto& elem1: nums1){
            for (auto& elem2: nums2)
                cnt[elem1+elem2]++;
        }
        for (auto& elem3: nums3){
            for (auto& elem4: nums4){
                if (cnt.contains(-(elem3+elem4)))
                    res += cnt[-(elem3+elem4)];
            }
        }
        return res;
    }
};