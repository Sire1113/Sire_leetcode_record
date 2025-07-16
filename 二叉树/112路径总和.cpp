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
    bool hasPathSumHelper(TreeNode* node, int sum, int& target){
        if (!node)
            return false;
        sum+=node->val;
        bool res = false;
        if (!node->left && !node->right){
            return (sum==target);
        }
        bool left = hasPathSumHelper(node->left, sum, target);
        bool right = hasPathSumHelper(node->right, sum, target);
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSumHelper(root, 0, targetSum);
    }
};