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
    pair<int, TreeNode*> lcaDeepestLeavesHelper(TreeNode* node, int depth, int& max_depth){
        if (!node)
            return {0, nullptr};
        depth++;
        if (!node->left && !node->right){
            if (depth >= max_depth){
                max_depth = depth;
                return {depth, node};
            }
            return {0, nullptr};
        }
        auto [left_depth, left_node] = lcaDeepestLeavesHelper(node->left, depth, max_depth);
        auto [right_depth, right_node] = lcaDeepestLeavesHelper(node->right, depth, max_depth);
        if (left_depth == right_depth && left_depth == max_depth)
            return {left_depth, node};
        else if (left_depth>right_depth && left_depth == max_depth)
            return {left_depth, left_node};
        else if (left_depth<right_depth && right_depth == max_depth)
            return {right_depth, right_node};
        return {0, nullptr};
    }


    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int max_depth = 0;
        return lcaDeepestLeavesHelper(root, 0, max_depth).second;
    }
};