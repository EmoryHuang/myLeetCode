/*
 * @Descroption: LeetCode 1844. �������������ַ��滻
 * @Author: EmoryHuang
 * @Date: 2021-07-15 19:19:58
 * @����˼·:
 * ���⣬�����ַ��������±�Ϊ�������������滻
 */

class Solution {
   public:
    string replaceDigits(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 1) s[i] = s[i - 1] + (s[i] - '0');
        }
        return s;
    }
};