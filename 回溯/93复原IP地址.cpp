class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void restoreIpAddressesHelper(string& s, int idx){
        if (path.size()>=4){
            if (path.size()==4 && idx== s.size())
                res.push_back(path);
            return;
        }
        if (s[idx] == '0'){
            path.push_back(0);
            restoreIpAddressesHelper(s,idx+1);
            path.pop_back();
            return;
        }
        for (int i=idx; i<s.size(); i++){
            int num = stoi(s.substr(idx, i-idx+1));
            if (num > 255)
                break;
            path.push_back(num);
            restoreIpAddressesHelper(s,i+1);
            path.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        restoreIpAddressesHelper(s,0);
        for (auto& elem1:res){
            string s = to_string(elem1[0]);
            for (int i=1;i<elem1.size(); i++)
                s+= ("."+to_string(elem1[i]));
            ret.push_back(s);
        }
        return ret;
    }
};