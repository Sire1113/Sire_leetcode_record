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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy = new ListNode{0, head};
        ListNode* end = dummy;
        ListNode* cur = head;
        bool isEven = false;
        if (!cur)
            return nullptr;
        while (cur){
            if (isEven)
                isEven = false;
            else {
                isEven = true;
                end = cur;
            }
            cur = cur->next;
        }
        cur = head;
        isEven = false;
        auto right = end;
        while (cur!=end){
            auto temp = right->next;
            right->next = cur->next;
            right = right->next;
            cur->next = cur->next->next;
            cur = cur->next;
            right->next = temp;
        }
        return dummy->next;
    }
};
