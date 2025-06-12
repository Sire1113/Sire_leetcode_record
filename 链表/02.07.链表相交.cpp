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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto cur1 = headA;
        int sizeA{}, sizeB{};
        auto cur2 = headB;
        while (cur1) {
            cur1 = cur1->next;
            sizeA++;
        }
        while (cur2) {
            cur2 = cur2->next;
            sizeB++;
        }
        ListNode* large_head = sizeA>sizeB?headA:headB;
        ListNode* small_head = sizeA<=sizeB?headA:headB;
        // cout << large_head->val << small_head->val;

        for (int i=0; i<(max(sizeA, sizeB) - min(sizeA, sizeB)); i++){
            // cout << large_head->val;
            large_head = large_head->next;
        }
        while (large_head&&small_head){
            cout << large_head->val << small_head->val << endl;
            if (small_head==large_head)
                return small_head;
            small_head = small_head->next;
            large_head = large_head->next;
        }
        return nullptr;
    }
};