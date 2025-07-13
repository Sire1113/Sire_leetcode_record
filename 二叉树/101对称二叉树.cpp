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
    bool isSymmetricHelper(TreeNode* left, TreeNode* right){
        if (!left && !right)
            return true;
        else if ((!left && right) || (left && !right))
            return false;
        else if (left->val != right->val)
            return false;
        else {
            bool inside = isSymmetricHelper(left->right, right->left);
            bool outside = isSymmetricHelper(left->left, right->right);
            return inside && outside;
        }
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelper(root->left, root->right);
    }
};