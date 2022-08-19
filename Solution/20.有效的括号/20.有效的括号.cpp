/*
 * @Descroption: LeetCode 20. 有效的括号
 * @Author: EmoryHuang
 * @Date: 2021-03-22 16:37:36
 * @解题思路:
 * 题目本身明显就是栈的应用，若遇到左括号入栈，遇到右括号时将对应栈顶左括号出栈，则遍历完所有括号后`stack`仍然为空
 * 方法一和二其实是一样的，只不过简洁一点
 */

class Solution {
   public:
    // 方法一
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 != 0) return false;
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);  //左括号入栈
            else {
                if (st.empty()) return false;
                if (s[i] == ')') {
                    if (st.top() != '(') return false;  //若栈顶不是左括号则false
                    st.pop();                           //出栈
                } else if (s[i] == '}') {
                    if (st.top() != '{') return false;
                    st.pop();
                } else if (s[i] == ']') {
                    if (st.top() != '[') return false;
                    st.pop();
                }
            }
        }
        return st.empty();  //栈为空则匹配
    }

    // 方法二
    // bool isValid(string s) {
    //     stack<char> st;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (s[i] == '(')
    //             st.push(')');  //找到左括号时，右括号入栈
    //         else if (s[i] == '[')
    //             st.push(']');
    //         else if (s[i] == '{')
    //             st.push('}');
    //         else if (!st.empty() && s[i] == st.top())  //找栈顶元素
    //             st.pop();
    //         else
    //             return false;
    //     }
    //     return st.empty();
    // }
};
