/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution {
public:
    bool isOperator(const string& token) {
        return (token == "+" || token == "-" || token == "*" || token == "/");
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk; 
        int res = 0; 
        int size = tokens.size(); 
        for (int i=0; i<size; i++) {
            string token = tokens[i];
            if (!isOperator(token)) {
               int num = atoi(token.c_str());
                stk.push(num);
                res = num; 
            } else {
                int num1 = stk.top(); 
                stk.pop(); 
                int num2 = stk.top(); 
                stk.pop(); 
                int tmp;
                if (token == "+") tmp = num1 + num2;
                else if (token == "-") tmp = num2 - num1;
                else if (token == "*") tmp = num1 * num2; 
                else tmp = num2 / num1; 
                stk.push(tmp);
                res = tmp;
            }
        }
        return res;
    }
};