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
    void longestZigZagHelper(TreeNode* node, int depth, int& res, int direction){
        if (!node)
            return;
        res = max(res, depth);
        if (direction==0){
            longestZigZagHelper(node->right, depth+1, res, 1);
            longestZigZagHelper(node->left, 1, res, 0);
        }
        else {
            longestZigZagHelper(node->right, 1, res, 1);
            longestZigZagHelper(node->left, depth+1, res, 0);
        }
    }
    int longestZigZag(TreeNode* root) {
        int res{};
        longestZigZagHelper(root->left, 1, res, 0);
        longestZigZagHelper(root->right, 1, res, 1);
        return res;
    }
};