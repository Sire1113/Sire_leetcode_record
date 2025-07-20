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
    TreeNode* pre = nullptr;
    void getMinimumDifferenceHelper(TreeNode* node, int& min_val){
        if (!node)
            return;
        getMinimumDifferenceHelper(node->left, min_val);
        if (pre)
            min_val = min(node->val - pre->val, min_val);
        pre = node;
        getMinimumDifferenceHelper(node->right, min_val);
    }
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        getMinimumDifferenceHelper(root, res);
        return res;
    }
};