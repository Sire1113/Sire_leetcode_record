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
    int getDecimalValue(ListNode* head) {
        int sum=0;
        int n = 0;
        auto cur = head;
        while (cur){
            n++;
            cur = cur->next;
        }
        n--;
        while (head){
            sum += (head->val) * (1 << n);
            n--;
            head = head->next;
        }
        return sum;
    }
};