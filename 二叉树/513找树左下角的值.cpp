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
    void findBottomLeftValueHelper(TreeNode* node, pair<int, int>& left_val, int depth){
        depth++;
        if (!node)
            return;
        if (node && !node->left && !node->right){
            if (depth > left_val.first){
                left_val.first = depth;
                left_val.second = node->val;
            }
            return;
        }
        findBottomLeftValueHelper(node->left, left_val, depth);
        findBottomLeftValueHelper(node->right, left_val, depth);
    }
    int findBottomLeftValue(TreeNode* root) {
        auto left_val = make_pair(0,root->val);
        findBottomLeftValueHelper(root, left_val, 0);
        return left_val.second;
    }
};