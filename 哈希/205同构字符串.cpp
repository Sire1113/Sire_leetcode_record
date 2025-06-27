class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> cnts;
        unordered_set<char> cntt;
        for (int i=0; i<s.size(); i++){
            if (cnts.contains(s[i])){
                if (cnts[s[i]] != t[i])
                    return false;
            }
            else
            if (cntt.contains(t[i]))
                return false;
            cnts[s[i]] = t[i];
            cntt.insert(t[i]);
        }
        return true;
    }
};