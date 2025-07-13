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
    bool isSubtreHelper(TreeNode* root, TreeNode* subRoot){
        if (!root && !subRoot)
            return true;
        else if ((!root && subRoot) || (root && !subRoot))
            return false;
        else if (root->val != subRoot->val)
            return false;
        else
            return isSubtreHelper(root->left, subRoot->left) && isSubtreHelper(root->right, subRoot->right);

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)
            return true;
        else if ((!root && subRoot) || (root && !subRoot))
            return false;
            // else if (root->val != subRoot->val)
            //     return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        else
            return isSubtreHelper(root, subRoot) || (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};