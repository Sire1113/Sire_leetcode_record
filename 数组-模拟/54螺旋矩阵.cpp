//
// Created by Sire1 on 25-6-5.
//
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int num=0;
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();// 3 4
        for (int tik = 0; tik < min(m,n)/2;tik++){
            for (int i=num;i<n-1-num;i++){
                res.push_back(matrix[num][i]);
            }
            for (int i=num;i<m-1-num;i++){
                res.push_back(matrix[i][n-1-num]);
            }
            for (int i=n-1-num;i>num;i--){
                res.push_back(matrix[m-num-1][i]);
            }
            for (int i=m-1-num;i>num;i--){
                res.push_back(matrix[i][num]);
            }
            num++;
        }
        if (res.size() != m*n){
            int it = max(m,n)-num;
            for (int p=num;p<it;p++){
                if (m<n) res.push_back(matrix[num][p]);
                else if (m>n)res.push_back(matrix[p][num]);
                else res.push_back(matrix[m/2][n/2]);
            }
        }
        return res;
    }
};