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
    void rangeSumBSTHelper(TreeNode* node, int& res, int& low, int& high){
        if (!node)
            return;
        if (node->val < low)
            rangeSumBSTHelper(node->right, res, low, high);
        else if (node->val > high)
            rangeSumBSTHelper(node->left, res, low, high);
        else {
            res+=node->val;
            rangeSumBSTHelper(node->left, res, low, high);
            rangeSumBSTHelper(node->right, res, low, high);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int res{};
        rangeSumBSTHelper(root, res, low, high);
        return res;
    }
};