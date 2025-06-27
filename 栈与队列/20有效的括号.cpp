class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1)
            return false;
        stack<int> cnt;
        for (const auto& elem: s){
            if (elem == '(' || elem == '{' || elem == '[')
                cnt.push(elem);
            else {
                if (cnt.empty())
                    return false;
                if (cnt.top() == elem-1 || cnt.top() == elem-2){
                    cnt.pop();
                }
                else
                    return false;
            }
        }
        return cnt.empty() ? true : false;
    }
};