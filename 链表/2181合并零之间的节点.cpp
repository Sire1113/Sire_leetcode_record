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
    ListNode* mergeNodes(ListNode* head) {
        ListNode d1{0, head};
        auto dummy = &d1;
        auto left = dummy;
        auto right = dummy->next;
        while (right){
            if (right->val != 0){
                left->val += right->val;
            }
            else if (right->next){
                left->next = right->next;
                left = left-> next;
                right = right->next;

            }
            else
                left ->next = nullptr;
            right = right->next;
        }
        return dummy->next;
    }
};