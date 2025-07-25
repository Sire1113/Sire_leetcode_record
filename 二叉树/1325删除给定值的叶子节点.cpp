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
    void removeLeafNodesHelper(TreeNode*& node, const int& target){
        if (!node)
            return;
        removeLeafNodesHelper(node->left, target);
        removeLeafNodesHelper(node->right, target);
        if (!node->left && !node->right && node->val==target){
            cout << node->val;
            node = nullptr;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        removeLeafNodesHelper(root, target);
        return root;
    }
};