//
// Created by Sire1 on 25-6-14.
//

#include "list_utils.h"
//using namespace mylist;

namespace mylist{

    ListNode::ListNode() : val(0), next(nullptr) {}
    ListNode::ListNode(int x) : val(x), next(nullptr) {}
    ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {}
    LinkList::LinkList(): head(nullptr){}
    LinkList::LinkList(ListNode* node) :head(node){}
    LinkList::LinkList(const std::vector<int> &nums) {
        this->head = generateList(nums);
    }
    LinkList::LinkList(int num) {
        head = new ListNode{num};
    }
    ListNode *LinkList::toHead() {
        return head;
    }
    void LinkList::printLinkList() {
        printList(head);
    }
    LinkList::~LinkList() {
        while (head){
            auto trash = head;
            head = head->next;
            delete trash;
        }
    }
    ListNode* generateList(const std::vector<int>& nums){
        ListNode* head = new ListNode;
        auto cur = head;
        for (auto& elem: nums){
            cur->next = new ListNode{elem};
            cur = cur -> next;
        }
        auto trash = head;
        head = head->next;
        delete trash;
        return head;
    }
    void printList(ListNode* head){
        while (head){
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }


}
