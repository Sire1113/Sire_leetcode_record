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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> nodes;
        if (root)
            nodes.push(root);
        while (!nodes.empty()){
            int size = nodes.size();
            int max_val = INT_MIN;
            while(size--){
                auto node = nodes.front();
                if (node->left)
                    nodes.push(node->left);
                if (node->right)
                    nodes.push(node->right);
                nodes.pop();
                max_val = max(max_val, node->val);
            }
            res.push_back(max_val);
        }
        return res;
    }
};