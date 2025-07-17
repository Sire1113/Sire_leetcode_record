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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0)
            return nullptr;
        int last_val = preorder[0];
        TreeNode* root = new TreeNode(last_val);
        if (preorder.size()==1)
            return root;
        int idx;
        for (int i=0; i<inorder.size(); i++){
            if (inorder[i] == last_val){
                idx = i;
                break;
            }
        }
        vector<int> in_left(inorder.begin(),inorder.begin()+idx);
        vector<int> in_right(inorder.begin()+idx+1,inorder.end());
        int idx2 = in_left.size();
        vector<int> pre_left(preorder.begin()+1,preorder.begin()+idx2+1);
        vector<int> pre_right(preorder.begin()+idx2+1,preorder.end());
        root->left = buildTree(pre_left, in_left);
        root->right = buildTree(pre_right, in_right);
        return root;
    }
};