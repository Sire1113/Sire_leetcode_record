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
    void binaryTreePathsHelper(TreeNode* node, string path, vector<string>& res){
        if (!node)
            return;
        path+= (string("->") + to_string(node->val));
        if (!node->left && !node->right){
            res.push_back(path.substr(2));
            return;
        }
        if (node->left)
            binaryTreePathsHelper(node->left, path, res);
        if (node->right)
            binaryTreePathsHelper(node->right, path, res);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string start = "";
        vector<string> res;
        binaryTreePathsHelper(root, start, res);
        return res;
    }
};