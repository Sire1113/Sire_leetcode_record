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
    int isBalancedHelper(TreeNode* node){
        if (!node)
            return 0;
        auto left = isBalancedHelper(node->left);
        if (left==-1)
            return -1;
        auto right = isBalancedHelper(node->right);
        if (right==-1)
            return -1;
        if (abs(left - right) <= 1)
            return 1+max(left, right);
        return -1;
    }
    bool isBalanced(TreeNode* root) {
        if (isBalancedHelper(root) != -1)
            return true;
        return false;
    }
};