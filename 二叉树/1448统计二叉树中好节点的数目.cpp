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
    void goodNodesHelper(TreeNode* node, int& cnt, int max_val){
        if (!node)
            return;
        if (node->val >= max_val){
            cnt++;
            max_val = node->val;
        }
        goodNodesHelper(node->left, cnt, max_val);
        goodNodesHelper(node->right, cnt, max_val);
    }
    int goodNodes(TreeNode* root) {
        int res{};
        goodNodesHelper(root, res, root->val);
        return res;
    }
};