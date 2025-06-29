class Solution {
public:
    int evalRPN(std::vector<string>& tokens) {
        int num1, num2;
        std::stack<int> cnt;
        for (auto& elem: tokens){
            if (elem != "+" && elem != "-" && elem != "*" && elem != "/")
                cnt.push(std::stoi(elem));
            else {
                num2 = cnt.top();
                cnt.pop();
                num1 = cnt.top();
                cnt.pop();
                switch(elem[0]){
                    case '+': cnt.push(num1+num2);break;
                    case '-': cnt.push(num1-num2);break;
                    case '*': cnt.push(num1*num2);break;
                    case '/': cnt.push(num1/num2);break;
                }
            }
        }
        return cnt.top();
    }
};