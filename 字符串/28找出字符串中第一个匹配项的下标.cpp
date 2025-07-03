class Solution {
public: // KMP算法
    vector<int> get_next(string pattern){
        int j{};
        vector<int> next_arr(pattern.size());
        for (int i=1; i< pattern.size(); i++){
            while (j>0 && pattern[i] != pattern[j])
                j = next_arr[j-1];
            if (pattern[i] == pattern[j]){
                j++;
                next_arr[i] = j;
            }
        }
        return next_arr;
    }
    int strStr(string haystack, string needle) {
        auto next_arr = get_next(needle);
        int j{};
        for (int i=0; i<haystack.size(); i++){
            while(j > 0 && haystack[i] != needle[j])
                j = next_arr[j-1];
            if (haystack[i] == needle[j]){
                j++;
            }
            if (j==needle.size())
                return i-needle.size()+1;
        }
        return -1;
    }
};