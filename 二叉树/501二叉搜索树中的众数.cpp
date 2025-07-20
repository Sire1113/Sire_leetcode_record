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
    void findModeHelper(TreeNode* cur, vector<int>& res, int& cnt, int& max_cnt, TreeNode*& pre){
        if (!cur)
            return;
        findModeHelper(cur->left, res, cnt, max_cnt, pre);
        if (pre){
            if (pre->val == cur->val)
                cnt++;
            else
                cnt = 1;
        }
        pre = cur;
        if (max_cnt == cnt)
            res.push_back(cur->val);
        else if (max_cnt < cnt){
            res.clear();
            max_cnt = cnt;
            res.push_back(cur->val);
        }
        findModeHelper(cur->right, res, cnt, max_cnt, pre);
    }
    vector<int> findMode(TreeNode* root) {
        TreeNode* pre = nullptr;
        vector<int> res;
        int cnt = 1, max_cnt = 0;
        findModeHelper(root, res, cnt, max_cnt, pre);
        return res;
    }
};