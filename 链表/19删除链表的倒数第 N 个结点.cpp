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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy{0, head};
        auto left = &dummy;
        auto right = left;
        while (n--)
            right = right->next;
        while (right->next){
            right = right->next;
            left = left->next;
        }
        // delete node
        auto trash = left->next;
        left->next = left->next->next;
        delete trash;
        return dummy.next;
    }
};