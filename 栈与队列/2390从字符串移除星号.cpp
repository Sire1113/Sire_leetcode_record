class Solution {
public:
    string removeStars(string s) {
        string res{};
        for (auto& elem: s){
            if (elem == '*')
                res.pop_back();
            else
                res.push_back(elem);
        }
        return res;
    }
};