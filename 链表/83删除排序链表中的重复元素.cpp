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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode d1{-101, head};
        auto left = &d1;
        auto right = (d1.next);
        while (right){
            if (right->val == left->val){
                auto trash = right;
                right = right->next;
                delete trash;
                left->next = right;
            }
            else {
                left = left->next;
                right = right->next;
            }
        }
        return d1.next;
    }
};