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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return nullptr;
        if (!root->left && !root->right && root->val != val)
            return nullptr;
        if (root->val == val)
            return root;
        TreeNode* node;
        if (root->val > val)
            node = searchBST(root->left, val);
        else
            node = searchBST(root->right, val);
        return node;
    }
};