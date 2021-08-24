/*
 * @Descroption: LeetCode 394. �ַ�������
 * @Author: EmoryHuang
 * @Date: 2021-08-24 16:23:43
 * @Method:
 * ʹ��ջ��¼ '[' ǰ�������ǰ��Ľ���Լ��ظ�����
 * ������� '[' ��ǰ��Ľ���Լ��ظ�������ջ
 * ������� ']' ������ظ�
 */

class Solution {
   public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        int num = 0;
        string ans;
        for (auto c : s) {
            if (isdigit(c))
                num = num * 10 + c - '0';
            else if (c == '[') {
                st.push({ans, num});
                ans.clear();
                num = 0;
            } else if (c == ']') {
                auto top = st.top();
                st.pop();
                string tmp;
                while (top.second--) tmp += ans;
                ans = top.first + tmp;
            } else
                ans += c;
        }
        return ans;
    }
};