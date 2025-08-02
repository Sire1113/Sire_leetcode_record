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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        auto cur = root;
        auto pre = cur;
        while (cur){
            pre = cur;
            if (val > cur->val)
                cur = cur->right;
            else
                cur = cur->left;
        }
        if (val > pre->val)
            pre->right = new TreeNode(val);
        else
            pre->left = new TreeNode(val);
        return root;
    }
};