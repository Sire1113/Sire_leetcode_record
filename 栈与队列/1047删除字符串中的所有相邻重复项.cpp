class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> cnt;
        for (auto& elem: s){
            if (cnt.empty())
                cnt.push(elem);
            else {
                if (cnt.top() == elem)
                    cnt.pop();
                else
                    cnt.push(elem);
            }
        }
        string res{};
        while (!cnt.empty()){
            res+=cnt.top();
            cnt.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};