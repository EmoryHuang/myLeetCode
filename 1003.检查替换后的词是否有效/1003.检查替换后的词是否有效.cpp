/*
 * @Descroption: LeetCode 1003. ����滻��Ĵ��Ƿ���Ч
 * @Author: EmoryHuang
 * @Date: 2021-04-26 13:20:36
 * @����˼·:
 * �����ַ�������Ϊ a,b ����ջ����Ϊ c �����μ�� c ǰ���Ƿ�Ϊ b,a��
 * �ٵ��� b,a������ж�ջ�Ƿ�Ϊ��
 */

class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) {
            if (ch == 'a' || ch == 'b') {  // ��Ϊa,b����ջ
                st.push(ch);
            } else if (ch == 'c') {  // ���cǰ���Ƿ�Ϊb,a
                if (st.empty()) return false;
                if (st.top() == 'b')
                    st.pop();  // ջ��Ϊb�򵯳�
                else
                    return false;
                if (st.empty()) return false;
                if (st.top() == 'a')
                    st.pop();  // ջ��Ϊa�򵯳�
                else
                    return false;
            }
        }
        return st.empty();
    }
};