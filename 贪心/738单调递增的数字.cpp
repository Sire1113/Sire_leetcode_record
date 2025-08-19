class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int flag = num.size();
        for (int i=num.size()-2; i>=0; i--){
            if (num[i] > num[i+1]){
                flag = i + 1;
                num[i] -= 1;
            }
        }
        for (int i=flag; i<num.size(); i++)
            num[i] = '9';
        return stoi(num);
    }
};