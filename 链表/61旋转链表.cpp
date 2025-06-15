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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* dummy = new ListNode{0, head};
        auto left = dummy;
        auto right = left;
        auto cur = head;
        int size{};
        while (cur){
            cur = cur->next;
            size++;
        }
        if (size==0)
            return nullptr;
        k = k % size;
        if (k==0)
            return head;
        while (k--)
            right = right->next;
        while (right->next){
            right = right->next;
            left = left->next;
        }
        auto temp = left->next;
        left->next = nullptr;
        right->next = dummy->next;
        dummy->next = temp;
        return temp;
    }
};