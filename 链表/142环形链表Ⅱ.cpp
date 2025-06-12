/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;
        ListNode* cycle_node;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast==slow){
                cycle_node = fast;
                cout << fast->val;
                break;
            }
        }
        if (!fast||!fast->next)
            return nullptr;
        auto cur1 = head;
        auto cur2 = cycle_node;
        while (cur1!=cur2){
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
};