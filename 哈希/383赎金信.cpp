
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> cnt{};
        for (const auto& s: magazine)
            cnt[s-'a']++;
        for (const auto& s: ransomNote){
            if (cnt[s-'a'] ==0)
                return false;
            else
                cnt[s-'a']--;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
