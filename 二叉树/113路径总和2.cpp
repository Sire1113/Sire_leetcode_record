/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void pathSumHelper(TreeNode* node, const int& target, vector<int>& path,int& sum, vector<vector<int>>& res){
        if (!node)
            return;
        sum+=node->val;
        path.push_back(node->val);
        if (!node->left && !node->right && sum == target)
            res.push_back(path);
        pathSumHelper(node->left, target, path, sum, res);
        pathSumHelper(node->right, target, path, sum, res);
        sum -= node->val;
        path.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        int sum{};
        pathSumHelper(root, targetSum, path, sum, res);
        return res;
    }
};