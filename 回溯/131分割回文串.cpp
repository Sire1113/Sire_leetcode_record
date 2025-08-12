class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    void partitionHelper(string& s, int idx){
        if (idx >= s.size()){
            res.push_back(path);
            return;
        }
        for (int i=idx; i< s.size(); i++){
            auto seq = s.substr(idx,i-idx+1);
            if (!isRightStr(seq))
                continue;
            else {
                path.push_back(seq);
            }
            partitionHelper(s, i+1);
            path.pop_back();
        }
    }
    bool isRightStr(string& s){
        int left{};
        int right = s.size()-1;
        while (left < right){
            if (s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        partitionHelper(s,0);
        return res;
    }
};