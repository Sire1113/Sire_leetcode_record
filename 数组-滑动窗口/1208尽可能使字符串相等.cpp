//
// Created by Sire1 on 25-6-8.
//
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int max_length = 0, left = 0;
        int current_cost = 0;
        for (int right = 0; right < s.length(); right++){
            current_cost += abs(static_cast<int>(s[right]-t[right]));
            while (current_cost > maxCost){
                current_cost -= abs(static_cast<int>(s[left]-t[left]));
                left++;
            }
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};