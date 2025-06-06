//
// Created by Sire1 on 25-6-6.
//
class Solution {
public:
    bool isNeed(char alpha){
        return alpha == 'a' || alpha == 'e' || alpha == 'i' || alpha == 'o' || alpha == 'u';
    }

    int maxVowels(string s, int k) {
        int max_length = 0, current = 0;
        for (int left = 0;left<s.length()+1-k;left++){
            if (left==0){
                for (char c:s.substr(0,k)){
                    if (isNeed(c)) {
                        current++;
                        max_length = current;
                    }
                }
            }
            else {
                if (isNeed(s[left-1])){
                    current--;
                }
                if (isNeed(s[left+k-1])){
                    current++;
                }
                max_length = max(max_length,current);
            }
        }
        return max_length;
    }
};