/*
 * @Descroption: LeetCode 921. 使括号有效的最少添加
 * @Author: EmoryHuang
 * @Date: 2021-07-23 20:33:39
 * @解题思路:
 * 使用栈存储
 * 遍历字符串，若读到 '('，则入栈；
 * 若读到 ')'，若此时栈是否为空，则说明没有匹配的 '('，cnt += 1，否则出栈
 */

class Solution {
   public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int cnt = 0;
        for (auto c : s) {
            if (c == '(')
                st.push(c);
            else if (st.empty())
                cnt += 1;
            else
                st.pop();
        }
        return cnt + st.size();
    }
};