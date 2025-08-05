class Solution {
public:
    void letterCombinationsHelper(string& digits, string& path, vector<string>& res, int idx){
        if (path.size() == digits.size()){
            res.push_back(path);
            return;
        }
        int num = digits[idx] - '0';
        string alphas;
        switch(num){
            case 2: alphas = "abc"; break;
            case 3: alphas = "def"; break;
            case 4: alphas = "ghi"; break;
            case 5: alphas = "jkl"; break;
            case 6: alphas = "mno"; break;
            case 7: alphas = "pqrs"; break;
            case 8: alphas = "tuv"; break;
            case 9: alphas = "wxyz"; break;
        }
        for (auto elem: alphas){
            path += elem;
            letterCombinationsHelper(digits, path, res, idx+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size()==0)
            return res;
        string path;
        letterCombinationsHelper(digits, path, res, 0);
        return res;
    }
};