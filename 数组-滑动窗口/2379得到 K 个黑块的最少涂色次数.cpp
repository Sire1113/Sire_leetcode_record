//
// Created by Sire1 on 25-6-6.
//
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int times = blocks.size();
        int current = 0;
        for (int i=0;i<blocks.size();i++){
            if (blocks[i] == 'W')
                current++;
            if (i<k-1)
                continue;
            times = min(times, current);
            if (blocks[i-k+1] == 'W')
                current--;
        }
        return times;
    }
};