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
    bool evaluateTree(TreeNode* node) {
        if (node->val < 2)
            return (node->val == 1?true:false);
        bool left = evaluateTree(node->left);
        bool right = evaluateTree(node->right);
        if (node->val == 2)
            return left || right;
        else
            return left && right;
    }
};