class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};