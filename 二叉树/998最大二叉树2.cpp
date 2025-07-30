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
    void insertIntoMaxTreeHelper(TreeNode*& node, int& val){
        if (!node || val > node->val){
            auto temp = node;
            node = new TreeNode(val);
            node->left = temp;
        }
        else {
            insertIntoMaxTreeHelper(node->right, val);
        }
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        insertIntoMaxTreeHelper(root, val);
        return root;
    }
};