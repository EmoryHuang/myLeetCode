/*
 * @Descroption: LeetCode 1190. ��תÿ�����ż���Ӵ�
 * @Author: EmoryHuang
 * @Date: 2021-05-26 15:35:17
 * @����˼·:
 * ͨ��ջ����
 * ����������ţ��� str ���뵽ջ�У����� str ��Ϊ�գ�������һ��
 * ����������ţ���˵���������˵�ǰ�㣬��Ҫ�� str ��ת�����ظ���һ��
 */

class Solution {
   public:
    string reverseParentheses(string s) {
        stack<string> st;
        string str;
        for (auto c : s) {
            if (c == '(') {
                st.push(str);  // ��������������ջ
                str = "";      // ���¼�¼�ַ�
            } else if (c == ')') {
                reverse(str.begin(), str.end());
                str = st.top() + str;  // ǰ����ַ����Ϻ�벿�ֵ��ַ�
                st.pop();
            } else
                str += c;
        }
        return str;
    }
};