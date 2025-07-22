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
    void pseudoPalindromicPathsHelper(TreeNode* node, unordered_set<int>& cnt, int& res){
        if (!node)
            return;
        if (cnt.contains(node->val))
            cnt.erase(node->val);
        else
            cnt.insert(node->val);
        if (cnt.size() <= 1 && !node->left && !node->right)
            res++;

        pseudoPalindromicPathsHelper(node->left, cnt, res);
        pseudoPalindromicPathsHelper(node->right, cnt, res);
        if (cnt.contains(node->val))
            cnt.erase(node->val);
        else
            cnt.insert(node->val);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_set<int> cnt;
        int res{};
        pseudoPalindromicPathsHelper(root, cnt, res);
        return res;
    }
};