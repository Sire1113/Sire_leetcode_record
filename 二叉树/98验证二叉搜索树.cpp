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
    bool isValidBSTHelper(TreeNode* node, long long& min, long long& max){
        if (!node)
            return true;
        if (node->val >= max || node->val <= min)
            return false;
        long long node_val = static_cast<long long>(node->val);
        return (isValidBSTHelper(node->left, min, node_val) && isValidBSTHelper(node->right, node_val, max));
    }
    bool isValidBST(TreeNode* root) {
        long long min_val = LLONG_MIN;
        long long max_val = LLONG_MAX;
        long long node_val = static_cast<long long>(root->val);
        return isValidBSTHelper(root->left, min_val, node_val) && isValidBSTHelper(root->right, node_val, max_val);
    }
};