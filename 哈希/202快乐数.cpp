
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cnt;
        while(n!=1){
            int sum = 0;
            while(n){
                sum += (n%10) * (n%10);
                n /= 10;
            }
            if (cnt.contains(sum))
                return false;
            cnt.insert(sum);
            n = sum;
        }
        return true;
    }
};