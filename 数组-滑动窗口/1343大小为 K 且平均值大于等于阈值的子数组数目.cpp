//
// Created by Sire1 on 25-6-6.
//
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        double current = 0;
        int cnt = 0;
        for (int i=0;i<arr.size();i++){
            current+=static_cast<double>(arr[i]) / k;
            if (i< k-1)
                continue;
            if (current >= threshold)
                cnt++;
            current -= static_cast<double>(arr[i-k+1]) / k;
        }
        return cnt;
    }
};