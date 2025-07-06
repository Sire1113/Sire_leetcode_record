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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<double> res;
        if (root)
            nodes.push(root);
        while (!nodes.empty()){
            int size = nodes.size();
            int size_cal = size;
            long long sum = 0;
            while (size--){
                auto node = nodes.front();
                if (node->left)
                    nodes.push(node->left);
                if (node->right)
                    nodes.push(node->right);
                nodes.pop();
                sum += node->val;
            }
            res.push_back(static_cast<double>(sum)/size_cal);
        }
        return res;
    }
};