/*
 * @Descroption: LeetCode 557. ��ת�ַ����еĵ��� III
 * @Author: EmoryHuang
 * @Date: 2021-05-04 14:58:36
 * @����˼·: ���⣬ԭ���㷨
 * �� `left` ��ǵ��ʵ������㣬�������ո���ת `left` �� `i`�����ȥ�������һ���ո�
 */

class Solution {
   public:
    string reverseWords(string s) {
        s += " ";
        int left = 0;  // ��¼�������λ��
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + left, s.begin() + i);
                left = i + 1;
            }
        }
        s.erase(s.end() - 1);
        return s;
    }
};