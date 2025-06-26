class MyQueue {
public:
    stack<int> in;
    stack<int> out;
public:

    MyQueue() {}

    void push(int x) {
        in.push(x);
    }

    int pop() {
        int res = this->peek();
        out.pop();
        return res;
    }

    int peek() {
        if (!out.empty())
            return out.top();
        else if(in.empty())
            return -1;
        while (!in.empty()){
            out.push(in.top());
            in.pop();
        }
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */