/*
 * @Descroption: LeetCode 20. ��Ч������
 * @Author: EmoryHuang
 * @Date: 2021-03-22 16:37:36
 * @����˼·:
 * ��Ŀ�������Ծ���ջ��Ӧ�ã���������������ջ������������ʱ����Ӧջ�������ų�ջ����������������ź�`stack`��ȻΪ��
 * ����һ�Ͷ���ʵ��һ���ģ�ֻ�������һ��
 */

class Solution {
   public:
    // ����һ
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 != 0) return false;
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);  //��������ջ
            else {
                if (st.empty()) return false;
                if (s[i] == ')') {
                    if (st.top() != '(') return false;  //��ջ��������������false
                    st.pop();                           //��ջ
                } else if (s[i] == '}') {
                    if (st.top() != '{') return false;
                    st.pop();
                } else if (s[i] == ']') {
                    if (st.top() != '[') return false;
                    st.pop();
                }
            }
        }
        return st.empty();  //ջΪ����ƥ��
    }

    // ������
    // bool isValid(string s) {
    //     stack<char> st;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (s[i] == '(')
    //             st.push(')');  //�ҵ�������ʱ����������ջ
    //         else if (s[i] == '[')
    //             st.push(']');
    //         else if (s[i] == '{')
    //             st.push('}');
    //         else if (!st.empty() && s[i] == st.top())  //��ջ��Ԫ��
    //             st.pop();
    //         else
    //             return false;
    //     }
    //     return st.empty();
    // }
};
