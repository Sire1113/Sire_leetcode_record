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

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size()==0)
            return nullptr;
        int max_idx = 0;
        for (int i=0; i < nums.size(); i++){
            if (nums[i] > nums[max_idx])
                max_idx = i;
        }
        TreeNode* node = new TreeNode(nums[max_idx]);
        if (nums.size()==1)
            return node;
        vector<int> left(nums.begin(), nums.begin()+max_idx);
        vector<int> right(nums.begin()+max_idx+1, nums.end());
        node->left = constructMaximumBinaryTree(left);
        node->right = constructMaximumBinaryTree(right);
        return node;


    }
};