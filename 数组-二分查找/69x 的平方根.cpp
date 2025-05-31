//
// Created by Sire1 on 25-5-30.
//
class Solution {
public:
    int mySqrt(int x) {
        if (x==0){
            return 0;
        }
        else if (x==1){
            return 1;
        }
        long long root{0L};
        for (root;root < x;root++){
            if (root * root > x){
                break;
            }
        }
        return root - 1;
    }
};