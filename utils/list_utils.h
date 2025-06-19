//
// Created by Sire1 on 25-6-14.
//

#ifndef LEETCODE_LIST_UTILS_H
#define LEETCODE_LIST_UTILS_H
#include <iostream>
#include <vector>
namespace mylist{
    class ListNode{
    public:
        int val;
        ListNode *next;
    public:
        ListNode();
        ListNode(int x);
        ListNode(int x, ListNode *next);
    };
    class LinkList{
    public:
        ListNode* head;
    public:
        LinkList();
        LinkList(const std::vector<int>& nums);
        LinkList(ListNode* node);
        ListNode* toHead();
        explicit LinkList(int num);
        void printLinkList();
        ~LinkList();

    };
    ListNode* generateList(const std::vector<int>& nums);
    void printList(ListNode* head);
}
#endif //LEETCODE_LIST_UTILS_H
