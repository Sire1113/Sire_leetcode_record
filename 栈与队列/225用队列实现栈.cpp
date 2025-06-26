class MyStack {
public:
    queue<int> my_queue;
public:
    MyStack() {

    }

    void push(int x) {
        my_queue.push(x);
    }

    int pop() {
        int size = my_queue.size() - 1;
        while (size--){
            my_queue.push(my_queue.front());
            my_queue.pop();
        }
        int res = my_queue.front();
        my_queue.pop();
        return res;
    }

    int top() {
        return my_queue.back();
    }

    bool empty() {
        return my_queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */