/**
* Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int mid, left = 1, right = n;
        while (left <= right){
            mid = left + (right - left) / 2;
            auto res = guess(mid);
            if (res == 0){
                return mid;
            }
            else if (res == 1){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};