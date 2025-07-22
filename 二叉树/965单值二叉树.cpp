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
    bool isUnivalTreeHelper(TreeNode* node, const int& val){
        if (!node)
            return true;
        if (node->val != val)
            return false;
        return isUnivalTreeHelper(node->left, val) && isUnivalTreeHelper(node->right, val);
    }
    bool isUnivalTree(TreeNode* root) {
        return isUnivalTreeHelper(root, root->val);
    }
};