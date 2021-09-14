/*
 * @Descroption: LeetCode 1021. ɾ������������
 * @Author: EmoryHuang
 * @Date: 2021-09-14 16:41:20
 * @Method:
 * ջ����ջ�ǿ�ʱ�����ż��� ans
 * ���� ( / ) ʱ��ջ/��ջ
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