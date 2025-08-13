class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    unordered_map<int, int> place;
    bool isValid(int& row, int& col){
        if (place.contains(col))
            return false;
        for (auto& [col1, row1]: place){
            float factor = (col-col1)/static_cast<float>(row-row1);
            if (factor==1 || factor==-1)
                return false;
        }
        return true;
    }
    void solveNQueensHelper(int& n, int row){
        if (row == n)
            res.push_back(path);
        string row_place(n,'.');
        for (int col=0; col<n; col++){
            if (row >0 && !isValid(row, col))
                continue;
            row_place[col] = 'Q';
            path.push_back(row_place);
            place[col] = row;
            solveNQueensHelper(n, row+1);
            row_place[col] = '.';
            path.pop_back();
            place.erase(col);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        solveNQueensHelper(n, 0);
        return res;
    }
};