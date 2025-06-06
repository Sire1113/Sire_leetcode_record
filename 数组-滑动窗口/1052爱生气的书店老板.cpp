//
// Created by Sire1 on 25-6-6.
//
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int max_val = 0;
        for (int i=0;i<customers.size();i++)
            max_val+=(customers[i]*(-1*grumpy[i] + 1));
        int current = max_val;
        for (int i=0;i<customers.size();i++){
            if (grumpy[i]==1)
                current+=customers[i];
            if (i<minutes-1)
                continue;
            max_val = max(max_val, current);
            if (grumpy[i-minutes+1] == 1)
                current-=customers[i-minutes+1];
        }
        return max_val;
    }
};