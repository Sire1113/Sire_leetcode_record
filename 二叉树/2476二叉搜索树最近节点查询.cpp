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
    void closestNodesHelper(TreeNode* node, vector<int>& nums){
        if (!node)
            return;
        closestNodesHelper(node->left, nums);
        nums.push_back(node->val);
        closestNodesHelper(node->right, nums);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        vector<vector<int>> res;
        closestNodesHelper(root, nums);
        for (auto target: queries){
            int left{}, right = nums.size()-1;
            bool find = false;
            while (left <= right){
                int mid = left + (right-left)/2;
                if (nums[mid] == target){
                    res.push_back({nums[mid], nums[mid]});
                    find = true;
                    break;
                }
                else if (nums[mid] > target)
                    right = mid-1;
                else
                    left = mid+1;
            }
            if (!find){
                if (left==nums.size())
                    res.push_back({nums[nums.size()-1], -1});
                else if ( right==-1)
                    res.push_back({-1,nums[0]});
                else
                    res.push_back({nums[right], nums[left]});
            }
        }
        return res;
    }
};