// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int mid, left = 1, right = n;
        while (left <= right){
            mid = left + (right - left) / 2;
            if (isBadVersion(mid)){
                if (mid > 1){
                    if (isBadVersion(mid - 1)){
                        right = mid - 1;
                    }
                    else {
                        return mid;
                    }
                }
                else {
                    return mid;
                }
            }
            else{
                left = mid + 1;
            }
        }
        return right;
    }
};