class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next){
            return nullptr;
        }
        ListNode* dummy = new ListNode{0, head};
        ListNode* right= dummy->next;
        auto left = dummy;
        while (right && right->next){
            right = right->next->next;
            left = left->next;
        }
        auto trash = left->next;
        left->next = left->next->next;
        delete trash;
        return dummy->next;
    }
};