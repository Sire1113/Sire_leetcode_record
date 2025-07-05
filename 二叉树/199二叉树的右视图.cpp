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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<int> res;
        if (root)
            nodes.push(root);
        while (!nodes.empty()){
            int size = nodes.size();
            vector<int> layer;
            while (size--){
                auto node = nodes.front();
                if (node->left)
                    nodes.push(node->left);
                if (node->right)
                    nodes.push(node->right);
                nodes.pop();
                layer.push_back(node->val);
            }
            res.push_back(layer[layer.size()-1]);
        }
        return res;

    }
};