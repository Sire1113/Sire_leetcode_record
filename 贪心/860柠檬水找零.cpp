class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> money;
        for (auto& bill:bills){
            if (bill == 5)
                money[5]++;
            else if (bill == 10){
                if (money[5] < 1)
                    return false;
                money[5]--;
                money[10]++;
            }
            else {
                if ((money[5] < 1 || money[10] < 1) && money[5] <3)
                    return false;
                else if (money[5] >= 1 && money[10] >= 1){
                    money[5]--;
                    money[10]--;
                }
                else
                    money[5] -= 3;
            }
        }
        return true;
    }
};