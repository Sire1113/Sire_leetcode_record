class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto first = headA;
        auto second = headB;
        bool endA = false, endB = false;
        while ((first || second) || (!endA || !endB)){
            if (first && second && (first == second))
                return first;
            if (!first && !endA){
                endA = true;
                first = headB;
            }
            else if (first)
                first = first->next;
            if (!second && !endB){
                endB = true;
                second = headA;
            }
            else if (second)
                second = second->next;
        }
        return nullptr;
    }
};