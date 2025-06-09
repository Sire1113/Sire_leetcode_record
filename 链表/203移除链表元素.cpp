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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        auto current = dummy;
        while (current->next){
            if (current->next->val == val){
                auto trash = current->next;
                current->next = current->next->next;
                delete trash;
            }
            else
                current = current->next;
        }
        auto trash = dummy;
        auto res = dummy->next;
        delete trash;
        return res;
    }
};