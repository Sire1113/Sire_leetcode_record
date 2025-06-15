ListNode* insertionSortList(ListNode* head) {
    ListNode* sorted_list = new ListNode{-5001, nullptr};
    auto pre = head;
    while (pre){
        auto cur2 = sorted_list;
        while (cur2->next && cur2->next->val < pre->val)
            cur2 = cur2->next;
        auto node = pre;
        pre = pre->next;
        node->next = cur2->next;
        cur2->next = node;
    }
    return sorted_list->next;
}