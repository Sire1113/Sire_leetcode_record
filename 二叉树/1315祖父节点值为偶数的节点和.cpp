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
    int sumEvenGrandparentHelper(TreeNode* node, int father, int grand){
        if (!node)
            return 0;
        int res{};
        if (grand%2==0)
            res += node->val;
        return res + sumEvenGrandparentHelper(node->left, node->val, father) + sumEvenGrandparentHelper(node->right, node->val, father);
    }
    int sumEvenGrandparent(TreeNode* root) {
        return sumEvenGrandparentHelper(root, 1, 1);
    }
};