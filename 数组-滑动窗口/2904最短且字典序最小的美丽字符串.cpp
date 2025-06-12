class Solution {
public:
    bool isNewer(const string& s1, const string& s2){
        int l1 = s1.length(), l2 = s2.length();
        if (l1 == 0) return true;
        if (l2 < l1) return true;
        else if (l2 > l1) return false;
        else {
            for (int i=0; i<l1; i++){
                if (s2[i] > s1[i])
                    return false;
                else if (s2[i] < s1[i])
                    return true;
            }
        }
        return true;
    }
    string shortestBeautifulSubstring(string s, int k) {
        unordered_map<char, int> cnt;
        string res{};
        int start = -1;
        int left = 0;
        int min_length = 1000000;
        for (int right=0; right < s.length(); right++){
            cnt[s[right]]++;
            while (cnt['1'] > k || s[left] == '0'){
                cnt[s[left]]--;
                left++;
            }
            if (cnt['1'] == k){
                string cur = s.substr(left, right - left + 1);
                if (isNewer(res, cur)){
                    res = cur;
                }
            }
        }
        return res;
    }
};