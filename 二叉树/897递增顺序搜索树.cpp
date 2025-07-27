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
    TreeNode* prev = new TreeNode();
    void increasingBSTHelper(TreeNode* node){
        if (!node)
            return;
        increasingBSTHelper(node->left);
        prev->right = new TreeNode(node->val);
        prev = prev->right;
        // cout << cur->val;
        increasingBSTHelper(node->right);
    }


    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = prev;
        // prev = dummy->right;
        increasingBSTHelper(root);
        return dummy->right;
    }
};
