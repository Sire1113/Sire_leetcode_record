//
// Created by Sire1 on 25-6-7.
//
class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> cnt;
        int left = 0, max_length = 0;
        for (int right = 0; right < s.length(); right++){
            cnt[s[right]]++;
            while (cnt[s[right]] > 2){
                cnt[s[left]]--;
                if (cnt[s[left]]==0)
                    cnt.erase(s[left]);
                left++;
            }
            int len = right - left + 1;
            max_length = max(max_length, len);
        }
        return max_length;
    }
};