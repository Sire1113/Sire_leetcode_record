//
// Created by Sire1 on 25-6-5.
//
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 0;
        int count = 1;
        vector<vector<int>> res(n);
        for (int p=0;p<n;p++){ // 初始化方法较本，有更简洁的方式。
            for (int num_elem = 0;num_elem<n;num_elem++)
                res[p].push_back(0);
        }
        for (int tik=0;tik<n/2;tik++){
            for (int i=num;i<n-1-num;i++){
                res[num][i] = count;
                count++;
            }
            for (int i=num;i<n-1-num;i++){
                res[i][n-1-num] = count;
                count++;
            }
            for (int i=n-1-num;i>num;i--){
                res[n-num-1][i] = count;
                count++;
            }
            for (int i=n-1-num;i>num;i--){
                res[i][num] = count;
                count++;
            }
            num++;
        }
        if (n%2==1){
            res[n/2][n/2] = n*n;
        }
        return res;
    }
};