class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode{0};
        auto cur = dummy;
        int val1, val2, c{};
        while (l1 || l2){
            if (l1){
                val1 = l1->val;
                l1 = l1->next;
            }
            else
                val1 = 0;
            if (l2){
                val2 = l2->val;
                l2 = l2->next;
            }
            else
                val2 = 0;
            int sum = (val1 + val2 + c) % 10;
            c = (val1 + val2 +c) / 10;
            auto node = new ListNode{sum, nullptr};
            cur->next = node;
            cur = node;
        }
        if (c==1)
            cur->next = new ListNode{c};
        return dummy->next;
    }
};