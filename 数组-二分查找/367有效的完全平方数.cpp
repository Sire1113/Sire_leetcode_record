class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num / 2 + 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            long long long_var = static_cast<long long>(mid);
            if (long_var * long_var > num){
                right = mid -1;
            }
            else if (long_var * long_var < num){
                left = mid + 1;
            }
            else{
                return true;
            }
        }
        return false;

    }
};