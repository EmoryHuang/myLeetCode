/*
 * @Descroption: LeetCode 150. 逆波兰表达式求值
 * @Author: EmoryHuang
 * @Date: 2021-03-20 14:53:36
 * @解题思路: 后缀表达式求值的问题，过程如下：
 * 1. 遍历表达式，遇到的数字首先放入栈中
 * 2. 若读到运算符，则弹出 `a` 和 `b`，执行 `b + a`，并将结果压入到栈中
 * 3. 若读到数字，将其直接放入栈中
 */

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int len = tokens.size();
        for (int i = 0; i < len; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int a = nums.top();  // a先弹出
                nums.pop();
                int b = nums.top();  // b后弹出
                nums.pop();
                if (tokens[i] == "+")
                    nums.push(b + a);  //注意a，b的运算顺序，将计算结果入栈
                else if (tokens[i] == "-")
                    nums.push(b - a);
                else if (tokens[i] == "*")
                    nums.push(b * a);
                else
                    nums.push(b / a);
            } else {
                nums.push(stoi(tokens[i]));  //转为int并将数字入栈
            }
        }
        return nums.top();
    }
};