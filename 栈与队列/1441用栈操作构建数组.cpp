class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int num{};
        for (int i=1; i<=n; i++){
            res.push_back("Push");
            if (target[num] != i)
                res.push_back("Pop");
            else
                num++;
            if (num == target.size())
                break;
        }
        return res;
    }
};