
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode{0, head};
        auto left1 = dummy;
        for (int i=0;i<left-1;i++)
            left1 = left1->next;
        auto pre = left1;
        auto cur = left1->next;
        auto p0 = left1;
        for (int i=0; i< right - left + 1; i++){
            auto temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        p0->next->next = cur;
        p0->next = pre;
        return dummy->next;
    }
};