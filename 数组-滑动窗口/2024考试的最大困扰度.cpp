//
// Created by Sire1 on 25-6-8.
//
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int max_length = 0, left = 0;
        unordered_map<char, int> cnt;
        for (int right = 0; right < answerKey.length(); right++){
            cnt[answerKey[right]]++;
            while (min(cnt['T'], cnt['F']) > k){
                cnt[answerKey[left]]--;
                left++;
            }
            max_length = max(max_length, right - left + 1);
        }
        return max_length;

    }
};