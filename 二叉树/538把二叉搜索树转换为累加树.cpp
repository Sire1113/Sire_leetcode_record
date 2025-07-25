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
    void convertBSTHelper(TreeNode* node, int& sum){
        if (!node)
            return;
        convertBSTHelper(node->right, sum);
        sum += node->val;
        node->val = sum;
        convertBSTHelper(node->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum{};
        convertBSTHelper(root, sum);
        return root;
    }
};