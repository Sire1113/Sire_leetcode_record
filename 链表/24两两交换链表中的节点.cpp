//
// Created by Sire1 on 25-6-11.
//
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
    ListNode* swapPairs(ListNode* head) {
        ListNode d{0, head};
        auto dummy = &d;
        auto current = dummy;
        while (current->next&&current->next->next){
            auto temp = current->next->next;
            current->next->next = temp->next;
            temp->next = current->next;
            current->next = temp;
            current = current->next->next;
        }
        return dummy->next;
    }
};