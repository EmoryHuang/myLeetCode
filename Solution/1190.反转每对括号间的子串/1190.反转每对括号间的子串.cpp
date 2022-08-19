/*
 * @Descroption: LeetCode 1190. 反转每对括号间的子串
 * @Author: EmoryHuang
 * @Date: 2021-05-26 15:35:17
 * @解题思路:
 * 通过栈处理
 * 如果是左括号，将 str 插入到栈中，并将 str 置为空，进入下一层
 * 如果是右括号，则说明遍历完了当前层，需要将 str 反转，返回给上一层
 */

class Solution {
   public:
    string reverseParentheses(string s) {
        stack<string> st;
        string str;
        for (auto c : s) {
            if (c == '(') {
                st.push(str);  // 遇到左括号则入栈
                str = "";      // 重新记录字符
            } else if (c == ')') {
                reverse(str.begin(), str.end());
                str = st.top() + str;  // 前面的字符加上后半部分的字符
                st.pop();
            } else
                str += c;
        }
        return str;
    }
};