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
    bool contains_one(TreeNode* node){
        if (!node)
            return false;
        auto left = contains_one(node->left);
        auto right = contains_one(node->right);
        if (!left)
            node->left = nullptr;
        if (!right)
            node->right = nullptr;
        return node->val==1?true:false || left || right;
    }
    TreeNode* pruneTree(TreeNode* root) {
        contains_one(root);
        if (root->val==0 && !root->left && !root->right)
            return nullptr;
        return root;
    }
};