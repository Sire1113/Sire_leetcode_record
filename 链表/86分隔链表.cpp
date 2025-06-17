class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode{0, head};
        ListNode* large_list = new ListNode{0};
        auto cur = dummy;
        auto cur2 = large_list;
        while (cur->next) {
            if (cur->next->val >= x){
                cur2->next = cur->next;
                cur->next = cur->next->next;
                cur2 = cur2->next;
            }
            else
                cur = cur->next;
        }
        cur2->next = nullptr;
        cur->next = large_list->next;
        return dummy->next;
    }
};