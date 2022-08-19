/*
 * @Descroption: LeetCode 921. ʹ������Ч���������
 * @Author: EmoryHuang
 * @Date: 2021-07-23 20:33:39
 * @����˼·:
 * ʹ��ջ�洢
 * �����ַ����������� '('������ջ��
 * ������ ')'������ʱջ�Ƿ�Ϊ�գ���˵��û��ƥ��� '('��cnt += 1�������ջ
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