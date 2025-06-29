class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> cnt;
        int push_idx{}, pop_idx{};
        for (int i=0; i<popped.size()+pushed.size(); i++){
            if (cnt.empty()){
                cnt.push(pushed[push_idx]);
                push_idx++;
            }
            else if (cnt.top() == popped[pop_idx]){
                cnt.pop();
                pop_idx++;
            }
            else if(push_idx!=pushed.size()){
                cnt.push(pushed[push_idx]);
                push_idx++;
            }
            else {
                if (pop_idx!=popped.size())
                    return false;
            }
        }
        return true;
    }
};