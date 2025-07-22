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
    void findSecondMinimumValueHelper(TreeNode* node, int& second, const int& min){
        if (!node)
            return;
        if (second <= min){
            if (node->val > min)
                second = node->val;
        }
        else {
            if (node->val >= second)
                return;
            else if (node->val > min)
                second = node->val;
        }
        findSecondMinimumValueHelper(node->left, second, min);
        findSecondMinimumValueHelper(node->right, second, min);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int res = -1;
        findSecondMinimumValueHelper(root, res, root->val);
        return res;
    }
};