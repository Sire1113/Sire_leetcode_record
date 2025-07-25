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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return nullptr;
        auto node = root1;
        if (!root1 && root2){
            return root2;
        }
        else if (root1 && !root2){
            return root1;
        }
        else {
            node->val += root2->val;
            node->left = mergeTrees(root1->left, root2->left);
            node ->right = mergeTrees(root1->right, root2->right);
        }
        return node;
    }
};