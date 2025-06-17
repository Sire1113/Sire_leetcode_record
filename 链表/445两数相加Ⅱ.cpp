#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
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
    ListNode* reverse_list(ListNode* head){
        ListNode* pre = nullptr, *cur = head;
        while (cur){
            auto temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse_list(l1);
        l2 = reverse_list(l2);
        ListNode* dummy = new ListNode{0};
        auto cur = dummy;
        int val1, val2, c{};
        while (l1 || l2){
            if (l1){
                val1 = l1->val;
                l1 = l1->next;
            }
            else
                val1 = 0;
            if (l2){
                val2 = l2->val;
                l2 = l2->next;
            }
            else
                val2 = 0;
            int sum = (val1 + val2 + c) % 10;
            c = (val1 + val2 +c) / 10;
            auto node = new ListNode{sum, nullptr};
            cur->next = node;
            cur = node;
        }
        if (c==1)
            cur->next = new ListNode{c};
        return reverse_list(dummy->next);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
