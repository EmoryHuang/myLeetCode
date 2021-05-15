/*
 * @Descroption: LeetCode 1003. 检查替换后的词是否有效
 * @Author: EmoryHuang
 * @Date: 2021-04-26 13:20:36
 * @解题思路:
 * 遍历字符串，若为 a,b 则入栈，若为 c 则依次检查 c 前面是否为 b,a，
 * 再弹出 b,a，最后判断栈是否为空
 */

class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) {
            if (ch == 'a' || ch == 'b') {  // 若为a,b则入栈
                st.push(ch);
            } else if (ch == 'c') {  // 检查c前面是否为b,a
                if (st.empty()) return false;
                if (st.top() == 'b')
                    st.pop();  // 栈顶为b则弹出
                else
                    return false;
                if (st.empty()) return false;
                if (st.top() == 'a')
                    st.pop();  // 栈顶为a则弹出
                else
                    return false;
            }
        }
        return st.empty();
    }
};