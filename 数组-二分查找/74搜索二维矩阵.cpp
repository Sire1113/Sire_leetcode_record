//
// Created by Sire1 on 25-5-30.
//
class Solution {
public:
    pair<int,bool> search_idx(vector<int>& arr, int& target){
        int left = 0, right = arr.size() - 1, mid;
        while (left <= right){
            mid = left + (right - left) / 2;
            if (target > arr[mid]){
                left = mid + 1;
            }
            else if (target < arr[mid]){
                right = mid - 1;
            }
            else {
                return make_pair(mid, true);
            }
        }
        return make_pair(left,false);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> first_elems;
        for (auto vec:matrix){
            first_elems.push_back(vec[0]);
        }
        auto [idx,flag1] = search_idx(first_elems, target);
        idx--;
        if (idx < 0 && !flag1){
            return false;
        }
        else if(flag1){
            return true;
        }
        auto search_vec = matrix[idx];
        auto [search_index,flag2] = search_idx(search_vec, target);
        if (flag2){
            return true;//search_index != search_vec.size()
        }
        else {
            return false;
        }

    }
};