/*
 * @Descroption: LeetCode 1021. 删除最外层的括号
 * @Author: EmoryHuang
 * @Date: 2021-09-14 16:41:20
 * @Method:
 * 栈，在栈非空时将括号加入 ans
 * 遇到 ( / ) 时入栈/出栈
 */

class Solution {
   public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;
        for (auto c : s) {
            if (c == ')') st.pop();
            if (!st.empty()) ans += c;
            if (c == '(') st.push('(');
        }
        return ans;
    }
};