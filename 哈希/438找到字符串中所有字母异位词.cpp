class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 哈希+定长滑动窗口
        // 注： 可以改成使用数组，速度更快
        int size = p.length();
        vector<int> res;
        unordered_map<char, int> word;
        for (auto& ch: p)
            word[ch]++;
        unordered_map<char, int> cnt;
        for (int i=0; i<s.length(); i++){
            cnt[s[i]]++;
            if (i<size-1)
                continue;
            if (cnt == word)
                res.push_back(i - size + 1);
            cnt[s[i-size+1]]--;
            if (cnt[s[i-size+1]]==0)
                cnt.erase(s[i-size+1]);
        }
        return res;
    }
};