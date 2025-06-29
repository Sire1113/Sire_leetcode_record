class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> res;
        int num1{},num2{};
        for (auto& op: operations){
            switch(op[0]){
                case 'D':
                    res.push(res.top() * 2);
                    break;
                case 'C':
                    res.pop();
                    break;
                case '+':
                    num1 = res.top();
                    res.pop();
                    num2 = res.top();
                    res.push(num1);
                    res.push(num1+num2);
                    break;
                default:
                    res.push(stoi(op));
                    break;
            }
        }
        int sum{};
        while (!res.empty()){
            sum += res.top();
            res.pop();
        }
        return sum;
    }
};