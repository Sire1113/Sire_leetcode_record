/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode{0, head};
        auto cur = dummy;
        unordered_set<int> cnt{nums.begin(), nums.end()};
        while (cur->next){
            if (cnt.contains(cur->next->val)){
                // auto trash = cur->next;
                cur->next = cur->next->next;
                // delete trash; 这里力扣会自动释放内存，不能手动删除
            }
            else {
                cur = cur->next;
            }
        }
        auto res = dummy->next;
        delete dummy;
        return res;
    }
};