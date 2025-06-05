//
// Created by Sire1 on 25-6-5.
//
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left = 0, current=0, max_length = 0;

        for (int right=0;right<fruits.size();right++){
            basket[fruits[right]]++;
            while (basket.size() > 2){
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0){
                    basket.erase(fruits[left]);
                }
                left++;
            }
            current = right-left + 1;
            max_length = max(max_length, current);

        }
        return max_length;
    }
};