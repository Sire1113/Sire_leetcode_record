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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* father = nullptr;
        unordered_map<int, TreeNode*> cnt;
        unordered_map<int, int> cnt_2;
        for (auto& elem: descriptions){
            int father_val = elem[0];
            TreeNode* sub_node = nullptr;
            if (cnt.contains(elem[1]))
                sub_node = cnt[elem[1]];
            else {
                sub_node = new TreeNode(elem[1]);
                cnt[sub_node->val] = sub_node;
            }
            if (!cnt.contains(father_val))
                cnt[father_val] = new TreeNode(father_val);
            if (elem[2] == 1)
                cnt[father_val]->left = sub_node;
            else
                cnt[father_val]->right = sub_node;
            cnt_2[sub_node->val]++;
        }

        for (auto [val, node]: cnt){
            if (!cnt_2.contains(val)){
                father = node;
                break;
            }
        }
        return father;
    }
};