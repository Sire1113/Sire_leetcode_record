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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto cur = head;
        while (cur->next){
            int num = gcd(cur->next->val, cur->val);
            ListNode* new_node = new ListNode{num, cur->next};
            cur->next = new_node;
            cur = cur->next->next;
        }
        return head;
    }
};