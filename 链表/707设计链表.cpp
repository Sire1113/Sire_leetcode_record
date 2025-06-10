//
// Created by Sire1 on 25-6-10.
//
class MyLinkedList {
public:
    class ListNode{
    public:
        int val{};
        ListNode* next{nullptr};
    public:
        ListNode() = default;
        ListNode(int value, ListNode* next_node)
                : val(value), next(next_node){}
    };
    int size{};
    ListNode* head = nullptr;
    MyLinkedList() = default;
public:
    int get(int index) {
        if (index > size - 1 || index < 0)
            return -1;
        ListNode dummy{0, head};
        ListNode* current = &dummy;
        int n = index + 1;
        while (n--){
            current = current->next;
        }
        return current-> val;
    }

    void addAtHead(int val) {
        size++;
        ListNode dummy{0, head};
        ListNode* new_node = new ListNode{val, head};
        dummy.next = new_node;
        head = dummy.next;
    }

    void addAtTail(int val) {
        size++;
        ListNode dummy{0, head};
        auto current = &dummy;
        while (current->next)
            current = current->next;
        ListNode* new_node = new ListNode{val, nullptr};
        current->next = new_node;
        head = dummy.next;
    }

    void addAtIndex(int index, int val) {
        if (index == size){
            addAtTail(val);
            return;
        }
        else if (index > size - 1 || index < 0)
            return;
        size++;
        ListNode dummy{0, head};
        auto current = &dummy;
        while (index--)
            current = current->next;
        ListNode* new_node = new ListNode{val, current->next};
        current->next = new_node;
        head = dummy.next;
    }

    void deleteAtIndex(int index) {
        if (index > size - 1 || index < 0)
            return;
        size--;
        ListNode dummy{0, head};
        auto current = &dummy;
        while (index--)
            current = current->next;
        auto trash = current->next;
        current->next = current->next->next;
        head = dummy.next;
        delete trash;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */