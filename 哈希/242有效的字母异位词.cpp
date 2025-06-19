
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        array<int, 26> cnt{};
        for (auto& elem: s)
            cnt[elem-'a']+=1;
        for (auto& elem: t)
            cnt[elem-'a']-=1;
        for (auto& time: cnt){
            if (time != 0)
                return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
