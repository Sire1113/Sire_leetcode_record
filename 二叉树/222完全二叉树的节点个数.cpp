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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        auto left = root->left;
        auto right = root->right;
        int left_depth{}, right_depth{};
        while (left){
            left = left->left;
            left_depth++;
        }
        while (right){
            right = right->right;
            right_depth++;
        }
        if (left_depth == right_depth)
            return (2 << left_depth) -1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};