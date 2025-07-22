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
    void leafSimilarHelper(TreeNode* node, vector<int>& leaves){
        if (!node)
            return;
        if (!node->left && !node->right)
            leaves.push_back(node->val);
        leafSimilarHelper(node->left, leaves);
        leafSimilarHelper(node->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        leafSimilarHelper(root1, leaves1);
        leafSimilarHelper(root2, leaves2);
        return (leaves1==leaves2);
    }
};