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
    void delNodesHelper(TreeNode*& node, const unordered_set<int>& cnt, vector<TreeNode*>& res){
        if (!node)
            return;
        delNodesHelper(node->left, cnt, res);
        delNodesHelper(node->right, cnt, res);
        if (cnt.contains(node->val)){
            if (node->left)
                res.push_back(node->left);
            if (node->right)
                res.push_back(node->right);
            node = nullptr;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> cnt(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res{};
        if (!cnt.contains(root->val))
            res.push_back(root);
        delNodesHelper(root, cnt, res);
        return res;
    }
};