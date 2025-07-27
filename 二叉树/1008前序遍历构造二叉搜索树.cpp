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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size()==0)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int i;
        for (i=1; i<preorder.size(); i++){
            if (preorder[i]>preorder[0])
                break;
        }
        vector<int> left(preorder.begin()+1, preorder.begin()+i);
        vector<int> right(preorder.begin()+i, preorder.end());
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        return root;
    }
};