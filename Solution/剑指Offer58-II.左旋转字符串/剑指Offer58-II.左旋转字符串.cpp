/*
 * @Descroption: ��ָ Offer 58 - II. ����ת�ַ���
 * @Author: EmoryHuang
 * @Date: 2021-07-07 19:43:36
 * @����˼·:
 * ����, ��Ƭ�����ƴ��
 */

class Solution {
   public:
    string reverseLeftWords(string s, int n) {
        string ans;
        int len = s.size();
        for (int i = n; i < n + len; i++) ans += s[i % len];
        return ans;
    }
};