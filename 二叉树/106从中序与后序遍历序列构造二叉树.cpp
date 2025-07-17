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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size()==0)
            return nullptr;
        int last_val = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(last_val);
        if (postorder.size()==1)
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
        vector<int> post_left(postorder.begin(),postorder.begin()+idx2);
        vector<int> post_right(postorder.begin()+idx2,postorder.end()-1);
        root->left = buildTree(in_left, post_left);
        root->right = buildTree(in_right, post_right);
        return root;
        // buildTree()
    }
};