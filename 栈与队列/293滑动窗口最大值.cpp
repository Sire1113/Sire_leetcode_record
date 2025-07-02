// hard 难度
class My_queue{
public:
    deque<int> my_que;
public:
    My_queue() = default;
    void push(int val){
        while (!my_que.empty() && val > my_que.back())
            my_que.pop_back();
        my_que.push_back(val);
    }
    void pop(int val){
        if (!my_que.empty() && my_que.front()==val)
            my_que.pop_front();
    }
    int get_max(){
        return my_que.front();
    }
};

class Solution {
public:
    My_queue que;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for (int i=0; i < nums.size(); i++){
            que.push(nums[i]);
            if (i < k-1)
                continue;
            res.push_back(que.get_max());
            que.pop(nums[i-k+1]);
        }
        return res;
    }
};