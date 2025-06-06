//
// Created by Sire1 on 25-6-6.
//

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int max_val = -100;
        int current = 0;
        int size = cardPoints.size();
        for (int i = 0; i < k * 2; i++){
            current+=cardPoints[(i+size-k)%size];
            cout << (i+size-k)%size;
            if (i<k-1)
                continue;
            max_val = max(max_val, current);
            current-= cardPoints[(i+size-2*k+1)%size];
        }
        return max_val;
    }
};