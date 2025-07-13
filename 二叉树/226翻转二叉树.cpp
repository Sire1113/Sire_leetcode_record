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
    void invertTreeHelper(TreeNode* cur) {
        if (!cur)
            return;
        swap(cur->left, cur->right);
        invertTreeHelper(cur->left);
        invertTreeHelper(cur->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invertTreeHelper(root);
        return root;
    }
};