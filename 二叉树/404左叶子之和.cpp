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
    void sumOfLeftLeavesHelper(TreeNode* node, int& res){
        if (!node)
            return ;
        if (node->left && !node->left->left && !node->left->right){
            res+= node->left->val;
        }
        sumOfLeftLeavesHelper(node->left ,res);
        sumOfLeftLeavesHelper(node->right, res);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int res{};
        sumOfLeftLeavesHelper(root, res);
        return res;
    }
};