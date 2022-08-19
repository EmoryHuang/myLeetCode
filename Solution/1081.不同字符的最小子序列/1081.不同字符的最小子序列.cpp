/*
 * @Descroption: LeetCode 1081. ��ͬ�ַ�����С������
 * @Author: EmoryHuang
 * @Date: 2021-08-03 13:55:59
 * @Method:
 * �����ַ���ά��һ������ջ��
 * ���ڸ��ַ����滹������ַ����򵯳���������ջ
 */

class Solution {
   public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> hash;
        // ��¼�ַ���������
        for (auto c : s) hash[c]++;
        string st;
        for (auto c : s) {
            // �����ǰ�ַ�����ջ��
            if (st.find(c) == string::npos) {
                // ά��һ������ջ
                // ���ڸ��ַ����滹������ַ����򵯳�
                while (!st.empty() && st.back() > c && hash[st.back()] > 0) st.pop_back();
                st.push_back(c);
            }
            hash[c]--;
        }
        return st;
    }
};